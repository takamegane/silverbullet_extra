Silverbullet_extra

swanmatch様のSiverbullet44の基板データを元に改変した基板です。
元データ(Silberbullet44)
https://github.com/swanmatch/silverbullet44


主な特徴としては
・MCUをRP2040 Promicroに変更
・LEDを南向きに変更
・ロータリーエンコーダを左右別に最大3つまで搭載可能
・親指クラスタ部はEC12ロータリーエンコーダとTHQWGD001とAZ1UBALLを選択可能
・Vial対応
です。
OLEDも利用できるようにしてありますが、ファーム未実装です。
OLED部分を用いてAZ1UBALLを取り付けることも可能です。

AZ1UBALLを利用する場合、左手→マウススクロール、右手トラックボールとして利用可能です。

ファームはまだ未完成のため、今後改良の余地はあるかと思います。
特に加速モードの切り替え、左右AZ1UBALLの操作切り替えなどは実装したいところです。

