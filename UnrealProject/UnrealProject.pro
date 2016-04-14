	TEMPLATE = app
	CONFIG += console
	CONFIG -= app_bundle
	CONFIG -= qt

	# Declare and assign specific variable, you may change this path to work (do not add \ at the end of path !)
	UNREAL_PATH = C:\Program Files (x86)\Epic Games
	VISUAL_PATH = C:\Program Files (x86)\Microsoft Visual Studio 14.0

	# Will define all unreal defines
	include(defines.pri)

	# Project source path (you may complete this)
	HEADERS += Source\UnrealProject\*.h
	SOURCES += Source\UnrealProject\*.cpp

	# Project include path (you also may complete this)
	INCLUDEPATH += Source\UnrealProject

	# include path for generated files
	INCLUDEPATH += Intermediate\Build\Win64\UE4Editor\Inc\UnrealProject

	# Will add all unreal include path 
	include(includes.pri)