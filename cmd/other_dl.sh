#! /bin/bash

### 引数はother172みたいにに指定する

# example
# ----------------------------------------------------------------
# ./cmd/other_dl other
# >>>> otherディレクトリ配下にotherのworkspaceが作成される
# ----------------------------------------------------------------

if [ $# -ne 1 ]; then
    echo "number of argments should be 1"
    return 1
fi


WORKDIR="/app"
CONTEST_DIR="${WORKDIR}/src/atcoder/other"
PROBLEM_DIR="${CONTEST_DIR}/$1"
TEMPLATE="${WORKDIR}/templates/atcoder.cpp"

### otherのフォルダを作成し，テストデータをダウンロードする
mkdir -p $CONTEST_DIR
cd $CONTEST_DIR
acc new $1

### ダウンロードしたテストデータに対して，cppファイルを作成する
PROBLEMS="${PROBLEM_DIR}/*"
for DIRPATH in $PROBLEMS; do
    if [ ! -d $DIRPATH ]; then
        continue
    fi

    cp -n $TEMPLATE "${DIRPATH}/$1_${DIRPATH##*/}.cpp"
done