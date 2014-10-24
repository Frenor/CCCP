@echo off
mkdir dependencies

@echo.
@echo ------Downloading vtk6.1.. 
::Background mode..
wget\wget.exe http://cccp.askevold.priv.no/repo/cccp/vtk6.1/64/ -P dependencies/ -r -nd -q -A.dll -l 1

@echo.
@echo ------Downloading freetype2.4..
wget\wget.exe http://cccp.askevold.priv.no/repo/cccp/freetype2.4/64/ -P dependencies/ -r -nd -q -A.dll -l 1

@echo.
@echo ------Downloading qt5.2 essentials..
wget\wget.exe http://cccp.askevold.priv.no/repo/cccp/qt5.2/64/ -P dependencies/ -r -nd -q -A.dll -l 1

@echo.
@echo ------Downloading occ6.7..
wget\wget.exe http://cccp.askevold.priv.no/repo/cccp/occ6.7.0/64/ -P dependencies/ -r -nd -q -A.dll -l 1

@echo.
@echo ------Downloading Gmsh..
wget\wget.exe http://cccp.askevold.priv.no/repo/cccp/ -P dependencies/ -r -nd -q -A.exe -l 1
