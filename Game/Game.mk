##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/l_tim/Documents/SFMLTest
ProjectPath            :=C:/Users/l_tim/Documents/SFMLTest/Game
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lara
Date                   :=20/09/2017
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
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) $(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) $(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Arc.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix): GameObject.cpp $(IntermediateDirectory)/GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameObject.cpp$(DependSuffix): GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameObject.cpp$(DependSuffix) -MM GameObject.cpp

$(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix): GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameObject.cpp$(PreprocessSuffix) GameObject.cpp

$(IntermediateDirectory)/Game.cpp$(ObjectSuffix): Game.cpp $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game.cpp$(DependSuffix) -MM Game.cpp

$(IntermediateDirectory)/Game.cpp$(PreprocessSuffix): Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix) Game.cpp

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix): PlayerBullet.cpp $(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/PlayerBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix): PlayerBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix) -MM PlayerBullet.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix): PlayerBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix) PlayerBullet.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp $(IntermediateDirectory)/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix): EnemyBullet.cpp $(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/EnemyBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix): EnemyBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix) -MM EnemyBullet.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix): EnemyBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix) EnemyBullet.cpp

$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix): Asteriod.cpp $(IntermediateDirectory)/Asteriod.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/Asteriod.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Asteriod.cpp$(DependSuffix): Asteriod.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Asteriod.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Asteriod.cpp$(DependSuffix) -MM Asteriod.cpp

$(IntermediateDirectory)/Asteriod.cpp$(PreprocessSuffix): Asteriod.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Asteriod.cpp$(PreprocessSuffix) Asteriod.cpp

$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix): LaserGenerator.cpp $(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/LaserGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix): LaserGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LaserGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LaserGenerator.cpp$(DependSuffix) -MM LaserGenerator.cpp

$(IntermediateDirectory)/LaserGenerator.cpp$(PreprocessSuffix): LaserGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LaserGenerator.cpp$(PreprocessSuffix) LaserGenerator.cpp

$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix): ArcSegment.cpp $(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/ArcSegment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix): ArcSegment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArcSegment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ArcSegment.cpp$(DependSuffix) -MM ArcSegment.cpp

$(IntermediateDirectory)/ArcSegment.cpp$(PreprocessSuffix): ArcSegment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArcSegment.cpp$(PreprocessSuffix) ArcSegment.cpp

$(IntermediateDirectory)/Arc.cpp$(ObjectSuffix): Arc.cpp $(IntermediateDirectory)/Arc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Documents/SFMLTest/Game/Arc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Arc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Arc.cpp$(DependSuffix): Arc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Arc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Arc.cpp$(DependSuffix) -MM Arc.cpp

$(IntermediateDirectory)/Arc.cpp$(PreprocessSuffix): Arc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Arc.cpp$(PreprocessSuffix) Arc.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


