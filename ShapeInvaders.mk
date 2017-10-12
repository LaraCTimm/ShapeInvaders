##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ShapeInvaders
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/l_tim/Documents/VleisInvaders
ProjectPath            :=C:/Users/l_tim/Documents/VleisInvaders
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lara
Date                   :=12/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ShapeInvaders.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Users\l_tim\Desktop\StevesDownloads\win-64\sfml\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\l_tim\Desktop\StevesDownloads\win-64\sfml\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe --std=gnu++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/Game_ArcSegment.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Asteriod.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_EnemyBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_FileReader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameTests.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Interface.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_LaserGenerator.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PlayerBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Satellite.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Game_ArcSegment.cpp$(ObjectSuffix): Game/ArcSegment.cpp $(IntermediateDirectory)/Game_ArcSegment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/ArcSegment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_ArcSegment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_ArcSegment.cpp$(DependSuffix): Game/ArcSegment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_ArcSegment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_ArcSegment.cpp$(DependSuffix) -MM Game/ArcSegment.cpp

$(IntermediateDirectory)/Game_ArcSegment.cpp$(PreprocessSuffix): Game/ArcSegment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_ArcSegment.cpp$(PreprocessSuffix) Game/ArcSegment.cpp

$(IntermediateDirectory)/Game_Asteriod.cpp$(ObjectSuffix): Game/Asteriod.cpp $(IntermediateDirectory)/Game_Asteriod.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Asteriod.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Asteriod.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Asteriod.cpp$(DependSuffix): Game/Asteriod.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Asteriod.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Asteriod.cpp$(DependSuffix) -MM Game/Asteriod.cpp

$(IntermediateDirectory)/Game_Asteriod.cpp$(PreprocessSuffix): Game/Asteriod.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Asteriod.cpp$(PreprocessSuffix) Game/Asteriod.cpp

$(IntermediateDirectory)/Game_Enemy.cpp$(ObjectSuffix): Game/Enemy.cpp $(IntermediateDirectory)/Game_Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Enemy.cpp$(DependSuffix): Game/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Enemy.cpp$(DependSuffix) -MM Game/Enemy.cpp

$(IntermediateDirectory)/Game_Enemy.cpp$(PreprocessSuffix): Game/Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Enemy.cpp$(PreprocessSuffix) Game/Enemy.cpp

$(IntermediateDirectory)/Game_EnemyBullet.cpp$(ObjectSuffix): Game/EnemyBullet.cpp $(IntermediateDirectory)/Game_EnemyBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/EnemyBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_EnemyBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_EnemyBullet.cpp$(DependSuffix): Game/EnemyBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_EnemyBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_EnemyBullet.cpp$(DependSuffix) -MM Game/EnemyBullet.cpp

$(IntermediateDirectory)/Game_EnemyBullet.cpp$(PreprocessSuffix): Game/EnemyBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_EnemyBullet.cpp$(PreprocessSuffix) Game/EnemyBullet.cpp

$(IntermediateDirectory)/Game_FileReader.cpp$(ObjectSuffix): Game/FileReader.cpp $(IntermediateDirectory)/Game_FileReader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/FileReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_FileReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_FileReader.cpp$(DependSuffix): Game/FileReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_FileReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_FileReader.cpp$(DependSuffix) -MM Game/FileReader.cpp

$(IntermediateDirectory)/Game_FileReader.cpp$(PreprocessSuffix): Game/FileReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_FileReader.cpp$(PreprocessSuffix) Game/FileReader.cpp

$(IntermediateDirectory)/Game_Game.cpp$(ObjectSuffix): Game/Game.cpp $(IntermediateDirectory)/Game_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Game.cpp$(DependSuffix): Game/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Game.cpp$(DependSuffix) -MM Game/Game.cpp

$(IntermediateDirectory)/Game_Game.cpp$(PreprocessSuffix): Game/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Game.cpp$(PreprocessSuffix) Game/Game.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix): Game/GameObject.cpp $(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix): Game/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix) -MM Game/GameObject.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix): Game/GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix) Game/GameObject.cpp

$(IntermediateDirectory)/Game_GameTests.cpp$(ObjectSuffix): Game/GameTests.cpp $(IntermediateDirectory)/Game_GameTests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/GameTests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameTests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameTests.cpp$(DependSuffix): Game/GameTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameTests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameTests.cpp$(DependSuffix) -MM Game/GameTests.cpp

$(IntermediateDirectory)/Game_GameTests.cpp$(PreprocessSuffix): Game/GameTests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameTests.cpp$(PreprocessSuffix) Game/GameTests.cpp

$(IntermediateDirectory)/Game_Interface.cpp$(ObjectSuffix): Game/Interface.cpp $(IntermediateDirectory)/Game_Interface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Interface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Interface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Interface.cpp$(DependSuffix): Game/Interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Interface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Interface.cpp$(DependSuffix) -MM Game/Interface.cpp

$(IntermediateDirectory)/Game_Interface.cpp$(PreprocessSuffix): Game/Interface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Interface.cpp$(PreprocessSuffix) Game/Interface.cpp

$(IntermediateDirectory)/Game_LaserGenerator.cpp$(ObjectSuffix): Game/LaserGenerator.cpp $(IntermediateDirectory)/Game_LaserGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/LaserGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_LaserGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_LaserGenerator.cpp$(DependSuffix): Game/LaserGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_LaserGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_LaserGenerator.cpp$(DependSuffix) -MM Game/LaserGenerator.cpp

$(IntermediateDirectory)/Game_LaserGenerator.cpp$(PreprocessSuffix): Game/LaserGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_LaserGenerator.cpp$(PreprocessSuffix) Game/LaserGenerator.cpp

$(IntermediateDirectory)/Game_main.cpp$(ObjectSuffix): Game/main.cpp $(IntermediateDirectory)/Game_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_main.cpp$(DependSuffix): Game/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_main.cpp$(DependSuffix) -MM Game/main.cpp

$(IntermediateDirectory)/Game_main.cpp$(PreprocessSuffix): Game/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_main.cpp$(PreprocessSuffix) Game/main.cpp

$(IntermediateDirectory)/Game_Player.cpp$(ObjectSuffix): Game/Player.cpp $(IntermediateDirectory)/Game_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Player.cpp$(DependSuffix): Game/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Player.cpp$(DependSuffix) -MM Game/Player.cpp

$(IntermediateDirectory)/Game_Player.cpp$(PreprocessSuffix): Game/Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Player.cpp$(PreprocessSuffix) Game/Player.cpp

$(IntermediateDirectory)/Game_PlayerBullet.cpp$(ObjectSuffix): Game/PlayerBullet.cpp $(IntermediateDirectory)/Game_PlayerBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/PlayerBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PlayerBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PlayerBullet.cpp$(DependSuffix): Game/PlayerBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PlayerBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PlayerBullet.cpp$(DependSuffix) -MM Game/PlayerBullet.cpp

$(IntermediateDirectory)/Game_PlayerBullet.cpp$(PreprocessSuffix): Game/PlayerBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PlayerBullet.cpp$(PreprocessSuffix) Game/PlayerBullet.cpp

$(IntermediateDirectory)/Game_Satellite.cpp$(ObjectSuffix): Game/Satellite.cpp $(IntermediateDirectory)/Game_Satellite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Satellite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Satellite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Satellite.cpp$(DependSuffix): Game/Satellite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Satellite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Satellite.cpp$(DependSuffix) -MM Game/Satellite.cpp

$(IntermediateDirectory)/Game_Satellite.cpp$(PreprocessSuffix): Game/Satellite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Satellite.cpp$(PreprocessSuffix) Game/Satellite.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


