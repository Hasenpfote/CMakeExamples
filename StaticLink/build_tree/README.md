[build_tree]
=============

# 用途

+ ビルドツリー内の静的ライブラリをリンクしアプリケーションを作成する  

# 構成(灰色部分は自動生成)

**build_tree/**  
　+ **builds/**  
　+ **cmake/**  
　　+ **compiler_settings.cmake**  
　　+ **utils.cmake**  
　+ **deploy/**  
　　+ bin/  
　　　+ Debug/  
　　　+ Release/  
　　+ include/  
　　　+ MyLib/  
　　　　+ bar/  
　　　　　+ bar.h  
　　　　+ foo.h  
　　+ lib/  
　　　+ Debug/  
　　　+ Release/  
　　+ share/  
　　　+ cmake/  
　　　　+ MyLib/  
　　　　　+ mylib-config-xxx.cmake  
　　　　　+ mylib-config.cmake  
　+ **external/**  
　　+ **MyLib/**  
　　　+ **cmake/**  
　　　　+ **compiler_settings.cmake**  
　　　　+ **utils.cmake**  
　　　+ **sources/**  
　　　　+ **bar/**  
　　　　　+ **bar.h**  
　　　　　+ **bar.cpp**  
　　　　+ **foo.h**  
　　　　+ **foo.cpp**  
　　　+ **CMakeLists.txt**  
　+ **sources/**  
　　　+ **main.cpp**  
　+ **CMakeLists.txt**  

# 操作と確認手順
1. App のビルドとインストール  
   build_tree/CMakeLists.txt を利用  

   CMAKE_INSTALL_PREFIX
       `/path/to/build_tree/deploy` を設定  
       ※ 絶対パス指定が必要  
       ※ deploy/ は予め作成しておく  

2. App の自動生成物の確認  
   build_tree/deploy/bin/  
