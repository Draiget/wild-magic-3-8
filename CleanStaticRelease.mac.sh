#!/bin/tcsh
cd Foundation
xcodebuild -project Foundation.xcodeproj -configuration WildMagic -target "Static Release" clean
cd ..

cd Renderers/OpenGLRenderer
xcodebuild -project AglRenderer.xcodeproj -configuration WildMagic -target "Static Release" clean
cd ../..

cd Applications
xcodebuild -project AglApplication.xcodeproj -configuration WildMagic -target "Static Release" clean
cd ..

cd SampleGraphics
set DIRS = `ls`
foreach dir (${DIRS})
    if (-d $dir) then
        echo $dir
        cd $dir
        xcodebuild -project $dir.xcodeproj -configuration WildMagic -target "Static Release" clean
        cd ..
    endif
end
cd ..

cd SampleImagics
set DIRS = `ls `
foreach dir (${DIRS})
    if (-d $dir) then
        echo $dir
        cd $dir
        xcodebuild -project $dir.xcodeproj -configuration WildMagic -target "Static Release" clean
        cd ..
    endif
end
cd ..

cd SampleMiscellaneous
set DIRS = `ls `
foreach dir (${DIRS})
    if (-d $dir) then
        echo $dir
        cd $dir
        xcodebuild -project $dir.xcodeproj -configuration WildMagic -target "Static Release" clean
        cd ..
    endif
end
cd ..

cd SamplePhysics
set DIRS = `ls `
foreach dir (${DIRS})
    if (-d $dir) then
        echo $dir
        cd $dir
        xcodebuild -project $dir.xcodeproj -configuration WildMagic -target "Static Release" clean
        cd ..
    endif
end
cd ..

cd SampleShaders
set DIRS = `ls `
foreach dir (${DIRS})
    if (-d $dir) then
        echo $dir
        cd $dir
        xcodebuild -project $dir.xcodeproj -configuration WildMagic -target "Static Release" clean
        cd ..
    endif
end
cd ..

