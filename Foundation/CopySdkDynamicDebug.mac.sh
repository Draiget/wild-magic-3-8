#!/bin/tcsh
mkdir -p ../Include
mkdir -p ../Library
mkdir -p ../Library/DebugDLL

set DIRS = `ls`
foreach dir (${DIRS})
    if (-d $dir && $dir != ${PROJECT_NAME}.xcode && $dir != ${PROJECT_NAME}.xcodeproj && $dir != build) then
        echo $dir
        cd $dir
        set CURDIR = `pwd`
        set HEADERS = `ls *.h *.inl *.mcr`
        foreach header (${HEADERS})
            cp -f "${CURDIR}"/$header ../../Include
        end
        cd ..
    endif
end

set RHEADERS = `ls *.h`
foreach rheader (${RHEADERS})
    cp -f "${SRCROOT}"/$rheader ../Include
end

cp -f "${SRCROOT}"/build/WildMagic/libWm3${PROJECT_NAME}Debug.dylib ../Library/DebugDLL/libWm3${PROJECT_NAME}Debug.dylib

