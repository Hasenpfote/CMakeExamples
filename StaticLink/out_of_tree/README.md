[out_of_tree]
=============

# 用途

+ ビルドツリー外の静的ライブラリをリンクしアプリケーションを作成する  

# 構成(灰色部分は自動生成)

**out_of_tree/**  
　+ **App/**  
　　+ **builds/**  
　　+ **cmake/**  
　　　+ **compiler_settings.cmake**  
　　　+ **utils.cmake**  
　　+ **deploy/**  
　　　+ bin/  
　　　　+ Debug/  
　　　　+ Release/  
　　+ **sources/**  
　　　+ **main.cpp**  
　　+ **CMakeLists.txt**  

　+ **MyLib/**  
　　+ **builds/**  
　　+ **cmake/**  
　　+ include/  
　　　+ foo.h  
　　　+ bar/  
　　　　+ bar.h  
　　+ lib/  
　　　+ Debug/  
　　　+ Release/  
　　+ share/  
　　　+ cmake/  
　　　　+ MyLib/  
　　　　　+ mylib-config.cmake  
　　　　　+ mylib-config-xxx.cmake  
　　+ **sources/**  
　　　+ **foo.h**  
　　　+ **foo.cpp**  
　　　+ **bar/**  
　　　　+ **bar.h**  
　　　　+ **bar.cpp**  
　　+ **CMakeLists.txt**  

# 操作と確認手順
1. MyLib のビルドとインストール
   out_of_tree/MyLib/CMakeLists.txt を利用  

   CMAKE_INSTALL_PREFIX
       `/path/to/out_of_tree/MyLib` を設定  
       ※ 絶対パス指定が必要  

   ここを変更するとインストール先を変更できるが、 out_of_tree/App/CMakeLists.txt で参照していることに注意

2. MyLib の自動生成物の確認  
   out_of_tree/MyLib/include/  
   out_of_tree/MyLib/lib/  
   out_of_tree/MyLib/share/  

3. App のビルドとインストール  
   out_of_tree/App/CMakeLists.txt を利用  

   CMAKE_INSTALL_PREFIX
       `/path/to/out_of_tree/App/deploy` を設定  
       ※ 絶対パス指定が必要  
       ※ deploy/ は予め作成しておく  

   MyLib_DIR
       `../MyLib/share/cmake/MyLib` を設定  
       ※ CMAKE_CURRENT_SOURCE_DIR からの相対パス指定が可能  

4. App の自動生成物の確認  
   out_of_tree/App/deploy/bin/  
