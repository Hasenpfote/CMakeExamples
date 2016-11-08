[CMakeExamples]
===============

# CMake  
 + [CMake](https://cmake.org/)  
 + [3.5.2 Documentation](https://cmake.org/cmake/help/v3.5/)
 + [CMake Wiki](https://cmake.org/Wiki/CMake)

# 用途  
  + CMake の用途別検証リポジトリ

# 検証環境
 + CMake 3.5 以上(用途によっては必須ではない)  
 + Windows 10 x86_64 / VC14
  + msbuild
 + Linux Mint 18 x86_64 / g++5.4.0 / Code::Blocks IDE 13.12
  + make

# TODO  
 +  

# NOTE
 + **source_group** によるグループ化
  + Code::Blocks IDE では機能自体が無視されているようである  
    デフォルトとして **CMAKE_CURRENT_SOURCE_DIR** からの相対パスとしてグループ化される  
 + **find_package** と config ファイル名  
    [find_package](https://cmake.org/cmake/help/v3.5/command/find_package.html?highlight=find%20package) には、  ハイフン記述の場合は小文字指定となっている。

   >Config mode attempts to locate a configuration file provided by the package to be found.
   >A cache entry called `<package>_DIR` is created to hold the directory containing the file.
   >By default the command searches for a package with the name <package>.
   >If the NAMES option is given the names following it are used instead of `<package>`.
   >The command searches for a file called `<name>Config.cmake` or `<lower-case-name>-config.cmake` for each name specified.

    Windows 環境の場合はルールが無視されていることを確認した。  
    `<PascalCaseName>-config.cmake` としてもエラーとならない。  
    一方 Lunux 環境の場合は仕様に準拠しているため `<lower-case-name>-config.cmake` 以外はエラーとなる。  
    `${PROJECT_NAME}`を利用する場合は明示的に `<lower-case-name>` としておかなければ、  
    クロスプラットフォームでは原因不明の理由で悩まされる。
    ```cmake
    # To lower.
    string(TOLOWER ${PROJECT_NAME} LOWER_PROJECT_NAME)
    set(EXPORT_NAME ${LOWER_PROJECT_NAME}-export)
    ```
