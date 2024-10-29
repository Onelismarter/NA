# 定义编译器    
CXX = g++    
# 定义LaTeX编译器    
LATEX = pdflatex    

# 定义编译选项    
CXXFLAGS = -Wall -g    
# 定义链接选项    
LDFLAGS = -L/usr/lib/python3.10/config-x86_64-linux-gnu -lpython3.10

# 定义头文件路径
INCLUDES = -I/usr/include/python3.10 \
           -I/home/lhy/.local/lib/python3.10/site-packages/numpy/core/include

# 定义C++源文件列表    
SRC_FILES_B = interpolation.cpp ProblemB.cpp
SRC_FILES_C = interpolation.cpp ProblemC.cpp
SRC_FILES_D = Hermite.cpp ProblemD.cpp
SRC_FILES_E = interpolation.cpp ProblemE.cpp
SRC_FILES_F = Bezier.cpp ProblemF.cpp

# 可执行文件名列表    
EXE_FILES = ProblemB ProblemC ProblemD ProblemE ProblemF

# 找到所有的.tex文件    
TEX_FILES = $(wildcard *.tex)    
# 从.tex文件生成PDF文件名列表    
PDF_FILES = $(TEX_FILES:.tex=.pdf)    

# 默认目标：编译所有C++和LaTeX文件    
all: $(EXE_FILES) $(PDF_FILES)    

# 编译并运行所有C++程序    
run: $(EXE_FILES)    
	@echo "Running all programs..."    
	@$(foreach exe,$(EXE_FILES), ./$(exe);)    

# 编译所有LaTeX文件到PDF    
pdf: $(PDF_FILES)    

# 特定目标：编译报告代码并生成报告的PDF文件    
report: $(PDF_FILES)    

# 直接编译C++源文件生成可执行文件
ProblemB: $(SRC_FILES_B)
#$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)
ProblemC: $(SRC_FILES_C)
#$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)
ProblemD: $(SRC_FILES_D)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
ProblemE: $(SRC_FILES_E)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)
ProblemF: $(SRC_FILES_F)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

# 编译LaTeX文件到PDF    
$(PDF_FILES): %.pdf: %.tex    
	$(LATEX) $<    
	$(LATEX) $<  # 可能需要编译两次以解决引用    

# 清理编译生成的文件    
clean:    
	rm -f $(EXE_FILES) *.log *.aux *.pdf *.bib *.xml *.fls *.gz *.fdb_latexmk  

# 伪目标    
.PHONY: all run pdf report clean    
