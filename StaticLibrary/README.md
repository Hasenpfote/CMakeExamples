[StaticLibrary]
===============

# 用途

+ 依存性のない自己完結するシンプルな静的ライブラリ(\*.lib \*.a etc)  

# 構成

**StaticLibrary/**  
　+ **builds/**  
　+ **sources/**  
　- **include/**  
　- **lib/**  
　+ **CMakeLists.txt**  

# For Windows
+ 検証環境  
 + Windows 10 x86_64
 + vc14  


+ CMake用作業ディレクトリ(どこでもいいがデフォルトは)
 + 32bit Debug and Release. → StaticLibrary/builds/windows/vc14/x86/  
 + 64bit Debug and Release. → StaticLibrary/builds/windows/vc14/x86_64/  


+ コマンド(CMake用作業ディレクトリで)  
 + msbuild ALL_BUILD.vcxproj /p:Configuration=[Debug|Release]  
 + msbuild INSTALL.vcxproj /p:Configuration=[Debug|Release]  

# For Linux
+ 検証環境  
 + Linux Mint 18 x86_64
 + g++ 5.4.0
 + Code::Blocks IDE 13.12


+ CMake設定  
 + CUSTOM_BUILD_TYPE を入力(空なら強制的に Release)  
 + FORCE_32BIT_BUILD をチェックすると環境に関係なく32bitバイナリを生成するよう強制する  
   ※ 要32bitライブラリなど


+ CMake用作業ディレクトリ(どこでもいいがデフォルトは)  
  + 32bit Debug. → StaticLibrary/builds/unix/codeblocks/x86/Debug/  
  + 32bit Release. → StaticLibrary/builds/unix/codeblocks/x86/Release/  
  + 64bit Debug. → StaticLibrary/builds/unix/codeblocks/x86_64/Debug/  
  + 64bit Release. → StaticLibrary/builds/unix/codeblocks/x86_64/Release/  


+ コマンド(CMake用作業ディレクトリで)  
 + make
 + make install

# 共通
+ ソース置き場  
  App/sources/ 以下、\*.h \*.cpp モジュール別ディレクトリなんでも  
+ ビルド/インストール後
 + StaticLibrary/include/ に StaticLibrary/sources/ 以下の \*.h がディレクトリ構成を維持し自動生成される  
 + StaticLibrary/lib/ にバイナリが自動生成される  
 + StaticLibrary/include/ と StaticLibrary/lib/ 自身も自動生成される  
