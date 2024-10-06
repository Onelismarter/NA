# 定义编译器    
CXX = g++    
# 定义LaTeX编译器    
LATEX = pdflatex    
    
# 定义编译选项    
CXXFLAGS = -Wall -g    
# 定义链接选项    
LDFLAGS =    
    
# 定义C++源文件列表    
SRC_FILES = ProblemB.cpp ProblemC.cpp ProblemD.cpp ProblemE.cpp ProblemF.cpp    
    
# 从源文件列表生成可执行文件名列表    
EXE_FILES = $(SRC_FILES:.cpp=)    
    
# 找到所有的.tex文件    
TEX_FILES = $(wildcard *.tex)    
# 从.tex文件生成PDF文件名列表    
PDF_FILES = $(TEX_FILES:.tex=.pdf)    
    
# 默认目标：编译所有C++和LaTeX文件    
all: $(EXE_FILES) $(PDF_FILES)    
    
# 编译并运行所有C++程序    
run: $(EXE_FILES)    
	@echo "Running all programs..."    
	@$(foreach exe,$(EXE_FILES),./$(exe);)    
    
# 编译所有LaTeX文件到PDF    
pdf: $(PDF_FILES)    
  
# 特定目标：编译报告代码并生成报告的PDF文件    
report: $(PDF_FILES)    
    
# 编译C++源文件到可执行文件    
$(EXE_FILES): %: %.cpp    
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)    
    
# 编译LaTeX文件到PDF    
$(PDF_FILES): %.pdf: %.tex    
	$(LATEX) $<    
	$(LATEX) $<  # 可能需要编译两次以解决引用    
    
# 清理编译生成的文件    
clean:    
	rm -f $(EXE_FILES) *.o *.log *.aux *.pdf *.bib *.xml   
    
# 伪目标    
.PHONY: all run pdf report clean    