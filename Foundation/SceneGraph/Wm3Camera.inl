// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline const float* Camera::GetFrustum () const
{
    return m_afFrustum;
}
//----------------------------------------------------------------------------
inline float Camera::GetDMin () const
{
    return m_afFrustum[VF_DMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetDMax () const
{
    return m_afFrustum[VF_DMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMin () const
{
    return m_afFrustum[VF_UMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMax () const
{
    return m_afFrustum[VF_UMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMin () const
{
    return m_afFrustum[VF_RMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMax () const
{
    return m_afFrustum[VF_RMAX];
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetLocation () const
{
    return Local.GetTranslate();
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetDVector () const
{
    return Local.GetRotate().GetColumn(0);
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetUVector () const
{
    return Local.GetRotate().GetColumn(1);
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetRVector () const
{
    return Local.GetRotate().GetColumn(2);
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetWorldLocation () const
{
    return World.GetTranslate();
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetWorldDVector () const
{
    return World.GetRotate().GetColumn(0);
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetWorldUVector () const
{
    return World.GetRotate().GetColumn(1);
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetWorldRVector () const
{
    return World.GetRotate().GetColumn(2);
}
//----------------------------------------------------------------------------
inline void Camera::SetPlaneState (unsigned int uiPlaneState)
{
    m_uiPlaneState = uiPlaneState;
}
//----------------------------------------------------------------------------
inline unsigned int Camera::GetPlaneState () const
{
    return m_uiPlaneState;
}
//----------------------------------------------------------------------------
inline int Camera::GetPlaneQuantity () const
{
    return m_iPlaneQuantity;
}
//----------------------------------------------------------------------------
inline const Plane3f* Camera::GetPlanes () const
{
    return m_akWPlane;
}
//----------------------------------------------------------------------------

