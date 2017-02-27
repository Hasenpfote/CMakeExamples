[GTestExample]
=============

# 用途

+ [Google Test](https://github.com/google/googletest "googletest
") を自動ダウンロードしユニットテスト環境を作成  
+ 簡単な [TDD](https://ja.wikipedia.org/wiki/%E3%83%86%E3%82%B9%E3%83%88%E9%A7%86%E5%8B%95%E9%96%8B%E7%99%BA "テスト駆動開発") 環境を用意できる

# 構成

**GTestExample/**  
　+ **cmake/**  
　　+ **compiler_settings.cmake**  
　　+ **gtest.cmake**  
　　+ **utils.cmake**  
　+ **sources/**  
　　　+ **bar.cpp**  
　　　+ **bar.h**  
　　　+ **foo.cpp**  
　　　+ **foo.h**  
　　　+ **main.cpp**  
　+ **test/**  
　　+ **bar/**  
　　　+ **bar_test.cpp**  
　　　+ **CMakeLists.txt**  
　　+ **foo/**  
　　　+ **foo_test.cpp**  
　　　+ **CMakeLists.txt**  
　+ **CMakeLists.txt**  
