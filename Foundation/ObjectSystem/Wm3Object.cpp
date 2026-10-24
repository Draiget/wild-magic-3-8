// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm3FoundationPCH.h"
#include "Wm3Object.h"
#include "Wm3Controller.h"
using namespace Wm3;

const Rtti Object::TYPE("Wm3.Object",0);
unsigned int Object::ms_uiNextID = 0;
THashTable<unsigned int,Object*>* Object::InUse = 0;
char Object::NameAppend = '#';
THashTable<String,FactoryFunction>* Object::ms_pkFactory = 0;
bool Object::ms_bStreamRegistered = false;

//----------------------------------------------------------------------------
Object::Object ()
{
    m_pkControllerList = 0;
    m_iReferences = 0;
    m_uiID = ms_uiNextID++;

    if (!InUse)
    {
        InUse = WM3_NEW THashTable<unsigned int,Object*>(1024);
    }

    InUse->Insert(m_uiID,this);
}
//----------------------------------------------------------------------------
Object::~Object ()
{
    RemoveAllControllers();
    assert(InUse);
    bool bFound = InUse->Remove(m_uiID);
    assert(bFound);
    (void)bFound;  // avoid compiler warning in release build
}
//----------------------------------------------------------------------------
void Object::DecrementReferences ()
{
    if (--m_iReferences == 0)
    {
        WM3_DELETE this;
    }
}
//----------------------------------------------------------------------------
void Object::PrintInUse (const char* acFilename, const char* acMessage)
{
    FILE* pkFile = System::Fopen(acFilename,"at");
    assert(pkFile);

    System::Fprintf(pkFile,"%s\n",acMessage);

    assert(InUse);
    unsigned int uiID = 0;
    Object** ppkObject = InUse->GetFirst(&uiID);
    while (ppkObject)
    {
        System::Fprintf(pkFile,"id = %6d , type = %s\n",uiID,
            (const char*)(*ppkObject)->GetType().GetName());
        ppkObject = InUse->GetNext(&uiID);
    }

    System::Fprintf(pkFile,"\n\n");
    System::Fclose(pkFile);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// controllers
//----------------------------------------------------------------------------
void Object::SetController (Controller* pkController)
{
    // Controllers may not be controlled.  This avoids arbitrarily complex
    // graphs of Objects.  It is possible to allowed controlled controllers,
    // but modify and proceed at your own risk...
    if (IsDerived(Controller::TYPE))
    {
        assert(false);
        return;
    }

    // controller must exist
    if (!pkController)
    {
        assert(pkController);
        return;
    }

    // check if controller is already in the list
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        if (pkList->Item() == pkController)
        {
            // controller already exists, nothing to do
            return;
        }
    }

    // bind controller to object
    pkController->SetObject(this);

    // controller not in current list, add it
    pkList = WM3_NEW TList<ControllerPtr>;
    pkList->Item() = pkController;
    pkList->Next() = m_pkControllerList;
    m_pkControllerList = pkList;
}
//----------------------------------------------------------------------------
int Object::GetControllerQuantity () const
{
    int iControllerQuantity = 0;

    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        iControllerQuantity++;
    }

    return iControllerQuantity;
}
//----------------------------------------------------------------------------
Controller* Object::GetController (int i) const
{
    assert(i >= 0);

    TList<ControllerPtr>* pkList = m_pkControllerList;
    for (int j = 0; j < i; j++, pkList = pkList->Next())
    {
        if (!pkList)
        {
            // i >= iControllerQuantity
            return 0;
        }
    }
    return (pkList ? pkList->Item() : 0);
}
//----------------------------------------------------------------------------
void Object::RemoveController (Controller* pkController)
{
    // check if controller is in list
    TList<ControllerPtr>* pkList = m_pkControllerList;
    TList<ControllerPtr>* pkPrev = 0;
    for (/**/; pkList; pkPrev = pkList, pkList = pkList->Next())
    {
        if (pkList->Item() == pkController)
        {
            // unbind controller from object
            pkController->SetObject(0);

            // remove the controller
            if (pkPrev)
            {
                // controller not at front of list
                pkPrev->Next() = pkList->Next();
            }
            else
            {
                // controller at front of list
                assert(pkList == m_pkControllerList);
                m_pkControllerList = pkList->Next();
            }
            pkList->Next() = 0;
            WM3_DELETE pkList;
            return;
        }
    }
}
//----------------------------------------------------------------------------
void Object::RemoveAllControllers ()
{
    while (m_pkControllerList)
    {
        m_pkControllerList->Item()->SetObject(0);
        m_pkControllerList->Item() = 0;
        TList<ControllerPtr>* pkSave = m_pkControllerList->Next();
        WM3_DELETE m_pkControllerList;
        m_pkControllerList = pkSave;
    }
}
//----------------------------------------------------------------------------
bool Object::UpdateControllers (double dAppTime)
{
    bool bSomeoneUpdated = false;
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        Controller* pkController = pkList->Item();
        assert(pkController);
        if (pkController->Update(dAppTime))
        {
            bSomeoneUpdated = true;
        }
    }
    return bSomeoneUpdated;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// copying
//----------------------------------------------------------------------------
ObjectPtr Object::Copy (bool bUniqueNames) const
{
    // save the object to a memory buffer
    Stream kSaveStream;
    kSaveStream.Insert((Object*)this);
    char* acBuffer = 0;
    int iBufferSize = 0;
    bool bSuccessful = kSaveStream.Save(acBuffer,iBufferSize);
    assert(bSuccessful);
    if (!bSuccessful)
    {
        return 0;
    }

    // load the object from the memory buffer
    Stream kLoadStream;
    bSuccessful = kLoadStream.Load(acBuffer,iBufferSize);
    assert(bSuccessful);
    if (!bSuccessful)
    {
        return 0;
    }
    WM3_DELETE[] acBuffer;

    if (bUniqueNames)
    {
        // generate unique names
        for (int i = 0; i < kLoadStream.GetOrderedQuantity(); i++)
        {
            Object* pkObject = kLoadStream.GetOrderedObject(i);
            assert(pkObject);
            const String& rkName = pkObject->GetName();
            int iLength = rkName.GetLength();
            if (iLength > 0)
            {
                // object has a name, append a character to make it unique
                const char* acName = (const char*)rkName;
                char* acNewName = WM3_NEW char[iLength+2];
                const size_t uiSize = (size_t)(iLength + 2);
                System::Strcpy(acNewName,uiSize,acName);
                acNewName[iLength] = NameAppend;
                acNewName[iLength+1] = 0;
                pkObject->SetName(String(acNewName));
                WM3_DELETE[] acNewName;
            }
        }
    }

    return kLoadStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* Object::GetObjectByName (const String& rkName)
{
    if (rkName == m_kName)
    {
        return this;
    }

    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        Controller* pkController = pkList->Item();
        if (pkController)
        {
            Object* pkFound = pkController->GetObjectByName(rkName);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void Object::GetAllObjectsByName (const String& rkName,
    TArray<Object*>& rkObjects)
{
    if (rkName == m_kName)
    {
        rkObjects.Append(this);
    }

    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        Controller* pkController = pkList->Item();
        if (pkController)
        {
            pkController->GetAllObjectsByName(rkName,rkObjects);
        }
    }
}
//----------------------------------------------------------------------------
Object* Object::GetObjectByID (unsigned int uiID)
{
    if (uiID == m_uiID)
    {
        return this;
    }

    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        Controller* pkController = pkList->Item();
        if (pkController)
        {
            Object* pkFound = pkController->GetObjectByID(uiID);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
bool Object::RegisterFactory ()
{
    if (!ms_bStreamRegistered)
    {
        Main::AddInitializer(Object::InitializeFactory);
        Main::AddTerminator(Object::TerminateFactory);
        ms_bStreamRegistered = true;
    }
    return ms_bStreamRegistered;
}
//----------------------------------------------------------------------------
void Object::InitializeFactory ()
{
    if (!ms_pkFactory)
    {
        ms_pkFactory =
            WM3_NEW THashTable<String,FactoryFunction>(FACTORY_MAP_SIZE);
    }
    ms_pkFactory->Insert(TYPE.GetName(),(FactoryFunction)Factory);
}
//----------------------------------------------------------------------------
void Object::TerminateFactory ()
{
    WM3_DELETE ms_pkFactory;
    ms_pkFactory = 0;
}
//----------------------------------------------------------------------------
Object* Object::Factory (Stream&)
{
    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
void Object::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM3_BEGIN_DEBUG_STREAM_LOAD;

    // get old address of object, save it for linking phase
    Object* pkLinkID;
    rkStream.Read(pkLinkID);
    rkStream.InsertInMap(pkLinkID,pkLink);

    // name of object
    rkStream.Read(m_kName);

    // link data
    int iQuantity;
    rkStream.Read(iQuantity);
    m_pkControllerList = 0;
    for (int i = 0; i < iQuantity; i++)
    {
        Object* pkObject;
        rkStream.Read(pkObject);
        pkLink->Add((Controller*)pkObject);

        // build pkController list, to be filled in by Link
        TList<ControllerPtr>* pkList = WM3_NEW TList<ControllerPtr>;
        pkList->Item() = 0;
        pkList->Next() = m_pkControllerList;
        m_pkControllerList = pkList;
    }

    WM3_END_DEBUG_STREAM_LOAD(Object);
}
//----------------------------------------------------------------------------
void Object::Link (Stream& rkStream, Stream::Link* pkLink)
{
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        Object* pkLinkID = pkLink->GetLinkID();
        pkList->Item() = (Controller*)rkStream.GetFromMap(pkLinkID);
    }
}
//----------------------------------------------------------------------------
bool Object::Register (Stream& rkStream) const
{
    Object* pkThis = (Object*)this;  // conceptual constness
    if (rkStream.InsertInMap(pkThis,0))
    {
        // Used to ensure the objects are saved in the order corresponding to
        // a depth-first traversal of the scene.
        rkStream.InsertInOrdered(pkThis);

        TList<ControllerPtr>* pkList;
        for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
        {
            Controller* pkController = pkList->Item();
            if (pkController)
            {
                pkController->Register(rkStream);
            }
        }

        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void Object::Save (Stream& rkStream) const
{
    WM3_BEGIN_DEBUG_STREAM_SAVE;

    // RTTI name for factory lookup on Load
    rkStream.Write(String(GetType().GetName()));

    // address of object for unique ID on Load/Link
    rkStream.Write((Object*)this);

    // name of object
    rkStream.Write(m_kName);

    // link data
    int iQuantity = 0;
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        iQuantity++;
    }

    rkStream.Write(iQuantity);

    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        rkStream.Write(pkList->Item());
    }

    WM3_END_DEBUG_STREAM_SAVE(Object);
}
//----------------------------------------------------------------------------
StringTree* Object::SaveStrings (const char*)
{
    int iCQuantity = (m_pkControllerList ? 1 : 0);
    StringTree* pkTree = WM3_NEW StringTree(4,iCQuantity);

    // strings
    pkTree->SetString(0,Format(&TYPE,GetName()));
    pkTree->SetString(1,Format("this =",this));
    pkTree->SetString(2,Format("ID   =",m_uiID));
    pkTree->SetString(3,Format("refs =",m_iReferences));

    // children
    if (m_pkControllerList)
    {
        // count the number of children for the string tree
        iCQuantity = 0;
        TList<ControllerPtr>* pkList;
        for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
        {
            iCQuantity++;
        }

        StringTree* pkCTree = WM3_NEW StringTree(1,iCQuantity);
        pkTree->SetChild(0,pkCTree);
        pkCTree->SetString(0,Format("controllers"));

        iCQuantity = 0;
        for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
        {
            pkCTree->SetChild(iCQuantity++,pkList->Item()->SaveStrings());
        }
    }

    return pkTree;
}
//----------------------------------------------------------------------------
int Object::GetMemoryUsed () const
{
    int iUsed = sizeof(Object) + m_kName.GetMemoryUsed();

    int iQuantity = 0;
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        iQuantity++;
    }
    iUsed += iQuantity*sizeof(TList<ControllerPtr>);

    return iUsed;
}
//----------------------------------------------------------------------------
int Object::GetDiskUsed (const StreamVersion&) const
{
    // RTTI name
    int iUsed = GetType().GetDiskUsed();

    // address of object
    iUsed += sizeof(this);

    // name of object
    iUsed += m_kName.GetDiskUsed();

    int iQuantity = 0;
    TList<ControllerPtr>* pkList;
    for (pkList = m_pkControllerList; pkList; pkList = pkList->Next())
    {
        iQuantity++;
    }
    iUsed += sizeof(int) + iQuantity*sizeof(ControllerPtr);

    return iUsed;
}
//----------------------------------------------------------------------------

