### int16型動作確認用アプリ

EmbeddedRTPSの動作確認をする（＝embeddedRTPS開発元が提供するのテストプログラムを実行する）ためのサンプルアプリです。
利用に当たっては、embeddedRTPS-STM32のリポジトリ内にある通信用アプリをビルドして実行する必要があります。

#### LINUX側の準備
1.適当なディレクトリに、embeddedRTPS-STM32のリポジトリをcloneします  
```
git clone --recursive https://github.com/embedded-software-laboratory/embeddedRTPS-STM32
```
2. 通信用アプリをビルドします  
```
cd embeddedRTPS-STM32
cd linux
mkdir build
cd build
cmake -DTHIRDPARTY=ON ..
make 
```
3. PC上のファイヤウォールの設定を切ります

#### STM側の設定
1. IPアドレスを設定します。  
`application/src/lwip.c L69-L80`  
```
  IP_ADDRESS[0] = 192;
  IP_ADDRESS[1] = 168;
  IP_ADDRESS[2] = 11;
  IP_ADDRESS[3] = 2;
  NETMASK_ADDRESS[0] = 255;
  NETMASK_ADDRESS[1] = 255;
  NETMASK_ADDRESS[2] = 255;
  NETMASK_ADDRESS[3] = 0;
  GATEWAY_ADDRESS[0] = 192;
  GATEWAY_ADDRESS[1] = 168;
  GATEWAY_ADDRESS[2] = 11;
  GATEWAY_ADDRESS[3] = 1;
  ```  
`embeddedRTPS/include/rtps/config.h L36-L37`  
```
const std::array<uint8_t, 4> IP_ADDRESS = {
    192, 168, 11, 2}; // Needs to be set in lwipcfg.h too.
```
2. 本アプリをビルドします

#### 実行
1. STM32側のアプリを、STM32CubeIDEのデバッガ機能などにより実行します
2. ビルドしたlinuxのアプリを実行します
3. 以下のように、linux側から送信されたデータがstmから返送され、その旨のメッセージが出れば成功です
```
Conducting new Test...
Send message to the STM32.
Received message from STM32 with len:10
0 : 10
1 : 10
2 : 10
3 : 10
4 : 10
5 : 10
6 : 10
7 : 10
8 : 10
9 : 10

Conducting new Test...
Send message to the STM32.

```
