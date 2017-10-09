##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/l_tim/Documents/VleisInvaders
ProjectPath            :=C:/Users/l_tim/Documents/VleisInvaders/Game
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lara
Date                   :=09/10/2017
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
ObjectsFileList        :="Game.txt"
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
Objects0=$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) $(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) $(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Player.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainMenu.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileReader.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix): ArcSegment.cpp $(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/ArcSegment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix): ArcSegment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix) -MM ArcSegment.cpp

$(IntermediateDirectory)/ArcSegment.cpp$(PreprocessSuffix): ArcSegment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArcSegment.cpp$(PreprocessSuffix) ArcSegment.cpp

$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix): Asteriod.cpp $(IntermediateDirectory)/Asteriod.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Asteriod.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Asteriod.cpp$(DependSuffix): Asteriod.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Asteriod.cpp$(DependSuffix) -MM Asteriod.cpp

$(IntermediateDirectory)/Asteriod.cpp$(PreprocessSuffix): Asteriod.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Asteriod.cpp$(PreprocessSuffix) Asteriod.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp $(IntermediateDirectory)/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix): EnemyBullet.cpp $(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/EnemyBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix): EnemyBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix) -MM EnemyBullet.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix): EnemyBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix) EnemyBullet.cpp

$(IntermediateDirectory)/Game.cpp$(ObjectSuffix): Game.cpp $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game.cpp$(DependSuffix) -MM Game.cpp

$(IntermediateDirectory)/Game.cpp$(PreprocessSuffix): Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix) Game.cpp

$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix): GameObject.cpp $(IntermediateDirectory)/GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameObject.cpp$(DependSuffix): GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameObject.cpp$(DependSuffix) -MM GameObject.cpp

$(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix): GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix) GameObject.cpp

$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix): GameTests.cpp $(IntermediateDirectory)/GameTests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/GameTests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameTests.cpp$(DependSuffix): GameTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameTests.cpp$(DependSuffix) -MM GameTests.cpp

$(IntermediateDirectory)/GameTests.cpp$(PreprocessSuffix): GameTests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameTests.cpp$(PreprocessSuffix) GameTests.cpp

$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix): LaserGenerator.cpp $(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/LaserGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix): LaserGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix) -MM LaserGenerator.cpp

$(IntermediateDirectory)/LaserGenerator.cpp$(PreprocessSuffix): LaserGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LaserGenerator.cpp$(PreprocessSuffix) LaserGenerator.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix): PlayerBullet.cpp $(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/PlayerBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix): PlayerBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix) -MM PlayerBullet.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix): PlayerBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix) PlayerBullet.cpp

$(IntermediateDirectory)/MainMenu.cpp$(ObjectSuffix): MainMenu.cpp $(IntermediateDirectory)/MainMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/MainMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainMenu.cpp$(DependSuffix): MainMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainMenu.cpp$(DependSuffix) -MM MainMenu.cpp

$(IntermediateDirectory)/MainMenu.cpp$(PreprocessSuffix): MainMenu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainMenu.cpp$(PreprocessSuffix) MainMenu.cpp

$(IntermediateDirectory)/FileReader.cpp$(ObjectSuffix): FileReader.cpp $(IntermediateDirectory)/FileReader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/VleisInvaders/Game/FileReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileReader.cpp$(DependSuffix): FileReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileReader.cpp$(DependSuffix) -MM FileReader.cpp

$(IntermediateDirectory)/FileReader.cpp$(PreprocessSuffix): FileReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileReader.cpp$(PreprocessSuffix) FileReader.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


