#!/bin/tcsh
cd ${SRCROOT}
set HEADERS = `ls *.h *.inl *.mcr`
foreach header (${HEADERS})
    cp -f "${SRCROOT}"/$header ../../Include
end

cp -f "${SRCROOT}"/build/WildMagic/libWm3${PROJECT_NAME}Release.dylib ../../Library/ReleaseDLL/libWm3${PROJECT_NAME}Release.dylib

