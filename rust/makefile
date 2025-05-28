
# 编译所有.rs文件的Makefile配置
TARGET := target
SRC := $(wildcard *.rs)
BIN := $(SRC:.rs=)

.PHONY: all clean

all: $(BIN)

%: %.rs
	rustc $< -o $(TARGET)/$@

clean:
	rm -rf $(TARGET)/*
	mkdir -p $(TARGET)
