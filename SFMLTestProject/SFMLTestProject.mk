##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SFMLTestProject
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/l_tim/Documents/SFMLTest
ProjectPath            :=C:/Users/l_tim/Documents/SFMLTest/SFMLTestProject
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lara
Date                   :=10/09/2017
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
ObjectsFileList        :="SFMLTestProject.txt"
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
Objects0=$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(ObjectSuffix): ../../../Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp $(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/l_tim/Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(DependSuffix): ../../../Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(DependSuffix) -MM ../../../Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp

$(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(PreprocessSuffix): ../../../Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Desktop_StevesDownloads_win-64_sfml_test-code_Pong.cpp$(PreprocessSuffix) ../../../Desktop/StevesDownloads/win-64/sfml/test-code/Pong.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


