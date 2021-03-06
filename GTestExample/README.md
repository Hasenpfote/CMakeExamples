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
　+ **CMakeLists.txt**  

# For Windows
+ 検証環境  
 + Windows 10 x86_64
 + vc14  

# For Linux
+ 検証環境  
  + Linux Mint 18 x86_64
  + g++ 5.4.0
  + Code::Blocks IDE 13.12

# 特記事項
+ **GTestExample/CMakeLists.txt** を cmake するとサブディレクトリ以下はすべて連鎖する
+ 新規テストは **GTestExample/test/CMakeLists.txt** に追加する必要がある
