#! /bin/bash

### 引数はarc172みたいにに指定する

# example
# ----------------------------------------------------------------
# ./cmd/arc_dl arc172
# >>>> arcディレクトリ配下にarc172のworkspaceが作成される
# ----------------------------------------------------------------

if [ $# -ne 1 ]; then
    echo "number of argments should be 1"
    return 1
fi


WORKDIR="/app"
CONTEST_DIR="${WORKDIR}/src/atcoder/arc"
PROBLEM_DIR="${CONTEST_DIR}/$1"
TEMPLATE="${WORKDIR}/templates/atcoder.cpp"

### arc172のフォルダを作成し，テストデータをダウンロードする
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