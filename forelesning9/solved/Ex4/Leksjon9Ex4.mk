##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Leksjon9Ex4
ConfigurationName      :=Debug
WorkspacePath          :=/home/hka/westerdals/CodeLite
ProjectPath            :=/home/hka/westerdals/CodeLite/Leksjon9Ex4
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hans K Aspenberg
Date                   :=26/10/17
CodeLitePath           :=/home/hka/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Leksjon9Ex4.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/list.c$(ObjectSuffix) $(IntermediateDirectory)/testlist.c$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/list.c$(ObjectSuffix): list.c $(IntermediateDirectory)/list.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/hka/westerdals/CodeLite/Leksjon9Ex4/list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list.c$(DependSuffix): list.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list.c$(ObjectSuffix) -MF$(IntermediateDirectory)/list.c$(DependSuffix) -MM list.c

$(IntermediateDirectory)/list.c$(PreprocessSuffix): list.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list.c$(PreprocessSuffix) list.c

$(IntermediateDirectory)/testlist.c$(ObjectSuffix): testlist.c $(IntermediateDirectory)/testlist.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/hka/westerdals/CodeLite/Leksjon9Ex4/testlist.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testlist.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testlist.c$(DependSuffix): testlist.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testlist.c$(ObjectSuffix) -MF$(IntermediateDirectory)/testlist.c$(DependSuffix) -MM testlist.c

$(IntermediateDirectory)/testlist.c$(PreprocessSuffix): testlist.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testlist.c$(PreprocessSuffix) testlist.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


