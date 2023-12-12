// BlackJackForLearn.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
#include <iostream>

#include"Card.h"
#include"Shoe.h"
#include"Player.h"
#include"Dealer.h"
using namespace std;

static Player* CreatePlayer()
{
    // 一人は必ず生成
    char name[32];
    cin >> name;
    return new Player(name);

    do
    {
        int select = 0;
        cout << "プレーヤーを追加しますか？\n"
            << "１．はい　２．いいえ" << flush;
        cin >> select;

        if (select == 1)
        {
            cin >> name;
            char name[32];
            return new Player(name);
        }
        else if (select == 2)
        {
            break;
        }
    } while (true);
}

// リザルト
static void ShowResult(Player& player, Dealer& dealer)
{
    printf("\n～Result～\n\n");
    // 手札をすべて表示
    printf("[あなたの手札]\n");
    player.ShowHand();
    printf("\n[ディーラーの手札]\n");
    dealer.ShowHand();

    // スコアが同じのとき
    if (player.CalcScore() == dealer.CalcScore())
    {
        printf("引き分けです");
    }
    else
    {
        cout << "勝者は " << ((player.CalcScore() > dealer.CalcScore()) ? "あなた" : "ディーラー") << " です。" << endl;
    }
}

static void ShowHand(Person& person)
{
    printf("==================\n");

    // 手札表示
    printf("%s\n", person.GetName());
    person.ShowHand();

    printf("==================\n");
}

//実行
int main()
{
    srand(time(NULL));

    Shoe shoe;
    Dealer dealer;

    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Player p4("Player4");

    Player playerList[] = {p1, p2, p3, p4};

    for (int i = 0; i < 4; ++i)
    {
        // ２枚引く
        playerList[i].Hit(shoe);
        playerList[i].Hit(shoe);
    }
    

    // 1枚引く
    dealer.Hit(shoe);

    // プレーヤーの手札表示
    for (int i = 0; i < 4; ++i)
    {
        ShowHand(playerList[i]);
    }
    
    ShowHand(dealer);

    // 1枚引く
    dealer.Hit(shoe);

    for (int i = 0; i < 4; ++i)
    {
        playerList[i].Play(shoe);
    }
    // まずはプレーヤーのターン処理

    // プレーヤーがスタンドした時の処理
    // ディーラーの自動処理
    dealer.Play(shoe);

    // リザルト表示
    for(int i = 0; i < 4; ++i)
    {
        ShowResult(playerList[i], dealer);
        printf("バーストしたので君の負けだよん :D\n");
    }
}
    

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
