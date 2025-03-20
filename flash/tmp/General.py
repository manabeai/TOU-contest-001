import os
from typing import List, Optional

def write_to_file(h: int, n: int, a: List[int], file_name: str, output_dir: Optional[str] = None) -> None:
    """
    整数 H, N と整数リスト A を指定された形式でファイルに出力する関数。

    Args:
        h (int): 整数 H。
        n (int): 整数 N。
        a (List[int]): 整数のリスト A。
        file_name (str): 出力するファイル名。
        output_dir (Optional[str]): 出力先ディレクトリ（デフォルトはコードが存在するディレクトリ）。
    """
    # 出力先ディレクトリが指定されていない場合は、コードが存在するディレクトリを使用
    if output_dir is None:
        output_dir = os.path.dirname(os.path.abspath(__file__))
    
    # 出力ファイルのフルパスを生成
    file_path = os.path.join(output_dir, file_name)

    # ディレクトリが存在しない場合は作成
    os.makedirs(output_dir, exist_ok=True)

    # ファイルに書き込む
    with open(file_path, 'w') as file:
        file.write(f"{h} {n}\n")  # HとNを書き込む
        file.write(" ".join(map(str, a)) + "\n")  # リストAを書き込む（空白区切り）

# 使用例
write_to_file(10, 5, [1, 2, 3, 4, 5], "output.txt")
