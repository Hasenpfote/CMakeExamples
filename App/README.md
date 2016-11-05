[App]
=====

# 用途

+ 依存性のない自己完結するシンプルなアプリケーション向け  

# 構成

**App/**  
　+ **builds/**  
　+ **sources/**  
　- **CMakeLists.txt**  

# For Windows
+ 検証環境  
 + Windows 10
 + vc14  


+ CMake用作業ディレクトリ(どこでもいいがデフォルトは)
 + 32bit Debug and Release. → App/builds/windows/vc14/x86/  
 + 64bit Debug and Release. → App/builds/windows/vc14/x86_64/  


+ コマンド(CMake用作業ディレクトリで)  
 + msbuild ALL_BUILD.vcxproj /p:Configuration=[Debug|Release]  
 + msbuild INSTALL.vcxproj /p:Configuration=[Debug|Release]  


+ ビルド/インストール後
 + cmake用作業ディレクトリ直下に bin/ が自動生成される

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
  + 32bit Debug. → App/builds/unix/codeblocks/x86/Debug/  
  + 32bit Release. → App/builds/unix/codeblocks/x86/Release/  
  + 64bit Debug. → App/builds/unix/codeblocks/x86_64/Debug/  
  + 64bit Release. → App/builds/unix/codeblocks/x86_64/Release/  


+ コマンド(CMake用作業ディレクトリで)  
 + make
 + make install

# 共通
+ ソース置き場  
  **sources/** 以下、\*.h \*.cpp モジュール別ディレクトリなんでも  
+ ビルド/インストール後
 + cmake用作業ディレクトリ直下に bin/ が自動生成される
