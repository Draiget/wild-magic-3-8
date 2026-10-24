#!/bin/tcsh
cd ${SRCROOT}
set HEADERS = `ls *.h *.inl *.mcr`
foreach header (${HEADERS})
    cp -f "${SRCROOT}"/$header ../../Include
end

cp -f "${SRCROOT}"/build/WildMagic/libWm3${PROJECT_NAME}Debug.a ../../Library/Debug/libWm3${PROJECT_NAME}Debug.a
ranlib ../../Library/Debug/libWm3${PROJECT_NAME}Debug.a

