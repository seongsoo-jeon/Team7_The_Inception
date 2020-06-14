#include <bangtal.h>
#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

SceneID scene1_s;                                  //첫번째화면
SceneID scene2_s;                                  //두번째화면
ObjectID Scene1_s, Scene2_s;                        //마우스콜백 설정 ( 배경 )
ObjectID potion1_s, potion2_s, potion3_s;           //물약 -- potion3_s=wmed1_k
ObjectID potion4_s, potion5_s;                      //합성 물약
ObjectID ask_locker_s, ask_board_s, ask_dream_s;    //문제
ObjectID left_s, right_s, left_s2, right_s2;                           //화살표
ObjectID keypad_dream_s;                            //꿈2가는 키패드
ObjectID glasses_s;                                 //꿈2 문제보는 안경
TimerID timer1_s, timer2_s, timer3_s, timer4_s;
SoundID paper_s, chest_s, locker_s, machine_s, hint_s;
float s1_s = 0.0f;
int num_s = 0;
float s2_s = 0.0f;
float s3_s = 0.0f;


bool real_1_lock = true;                            //현실 상자 잠금

bool dream_1_lock = true;                           //첫 번째 꿈 이후 물약2 보이기

bool dream_2_lock = true;                           //두 번째 꿈

//----------------------------------------------------------------------

SceneID scene1_k, scene2_k, scene3_k, scene4_k, scene5_k, scene6_k;
ObjectID note_k, black_k, note1_k, lock_k, note2_k, wmed1_k, hole_k, machine1_k, machine2_k, mem_k, memB_k, mem1_k, left_k;
bool closed_k = true;
bool closed1_k = true;
TimerID timer1_k, timer2_k, timer3_k;
const Second animationTime = 0.05f;
float k_k = 0.0f;
int num_k = 0;
float h_k = 0.0f;
float k1_k = 0.0f;
int num1_k = 0;
float h1_k = 0.0f;
int dreamcheck_k = 0;
int dreamcheck1_k = 0;
int holecheck_k = 0;
SceneID  scene_p;
TimerID timerS;
int mixcount = 2;
const Second animation = 2.f;
int k = 1;
SceneID initScene[3];
ObjectID startbutton;
SoundID machines_k, crack_k;
//------------------------------------------------------------------------G
SceneID initScene_loading, dream_1_main, dream_1_quiz, dream_1_lab;
ObjectID d1_door, d1_hint, d1_puzzle, exit_d1_quiz, d1_s2_computer, d1_s2_drawer, d1_s2_machine, door_d1_s2,
//악기
d1_play1, d1_play2, d1_play3, d1_play4, d1_play5, d1_play6;
SoundID intro_BGM, main_BGM, dream1_BGM, dream1_BGM_2, dream_1_door, dream2_BGM,
d1_1, d1_2, d1_3, d1_4, d1_5, d1_6,
zombie1, zombie2, zombie3;
TimerID loading, timer_animation, go_dream_1, out_dream_1, out_dream_12, exit_dream_1;
//타이머 애니메이션
float dream1_light = 0.0f;
float main_light = 0.0f;
float g1 = 0.0f;
//변수
bool dream1_quiz = true, dream1_door = true, get_potion_1 = true, get_potion_2 = true, get_potion_3 = true;
int music_d1 = 0;
int music_d12 = 0;

void mix()
{
    char image[10];
    for (int i = 0; i < 3; i++) {
        sprintf_s(image, "%d.png", i + 1);
        initScene[i] = createScene("?", image);
    }

}

void sceneCallback(SceneID scene, EventID event)
{
    if (scene == scene_p) {
        if (event == EventID::EVENT_ENTER_SCENE)
            srand((unsigned int)time(NULL));
        playSound(intro_BGM, true);
        timerS = createTimer();
        setTimer(timerS, animation);
        startTimer(timerS);
    }
    if (scene == initScene[1]) {
        if (event == EventID::EVENT_ENTER_SCENE) {
        }
    }

}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown)
{
    ObjectID object = createObject(image);
    locateObject(object, scene, x, y);

    if (shown) {
        showObject(object);
    }

    return object;
}

void game_start() {
    //시작 1,2
    scene1_s = createScene("room1", "배경1.jpg");
    scene2_s = createScene("room2", "배경2.jpg");
    //--------------------------------------------------
    //로딩
    initScene_loading = createScene(" ", "3_loading.png");
    //꿈1
    dream_1_main = createScene(" ", "dream_1_stage1.png");
    dream_1_quiz = createScene(" ", "dream_1_button_all.png");
    dream_1_lab = createScene(" ", "dream_1_stage2.png");

    //------------------------------------------------------
    //꿈2, 시작3
    scene1_k = createScene(" ", "main_k2.png");
    scene2_k = createScene(" ", "잠금화면_k1.png");
    scene3_k = createScene(" ", "조합도_k.png");
    scene4_k = createScene("room3", "마지막화면.jpg");
    scene5_k = createScene("room3", "구멍.png");
    scene6_k = createScene(" ", "병원.png");
    scene_p = createScene(" ", "1.png");
}

void object_create() {
    Scene1_s = createObject("배경1.jpg", scene1_s, 0, 0, true);
    Scene2_s = createObject("배경2.jpg", scene2_s, 0, 0, true);

    ask_locker_s = createObject("사물함문제.png");
    ask_board_s = createObject("칠판문제.png");

    ask_dream_s = createObject("꿈문제.png");
    keypad_dream_s = createObject("키패드.png", scene1_s, 823, 257, false);    //꿈1에서 나오면 true

    potion1_s = createObject("물약1.png");
    potion2_s = createObject("물약2.png");
    potion4_s = createObject("물약4.png");
    potion5_s = createObject("물약5.png");

    glasses_s = createObject("안경.png", scene1_s, 160, 10, false);
    hint_s = createObject("문제힌트1.png");

    right_s = createObject("오른쪽화살표.png", scene1_s, 1150, 10, true);
    left_s = createObject("왼쪽화살표.png", scene2_s, 10, 10, true);
    right_s2 = createObject("오른쪽화살표.png", scene2_s, 1150, 10, true);
    left_s2 = createObject("왼쪽화살표.png", scene4_k, 10, 10, true);

    scaleObject(right_s, 0.2f);
    scaleObject(left_s, 0.2f);
    scaleObject(right_s2, 0.2f);
    scaleObject(left_s2, 0.2f);
    scaleObject(glasses_s, 0.1f);

    //-------------------------------------------------------------------------
    //dream1
    d1_door = createObject("dream_1_door_927,395.png", dream_1_main, 927, 324, true);
    d1_hint = createObject("dream_1_hint_527,497.png", dream_1_main, 527, 222, true);
    d1_puzzle = createObject("dream_1_puzzle1_71,697.png", dream_1_main, 71, 22, true);

    //dream1 music
    d1_play1 = createObject("button1_43,204.png", dream_1_quiz, 331 + 43, 515, true);
    d1_play2 = createObject("button2_408,202.png", dream_1_quiz, 331 + 408, 518, true);
    d1_play3 = createObject("button3_42,436.png", dream_1_quiz, 331 + 42, 283, true);
    d1_play4 = createObject("button4_409,436.png", dream_1_quiz, 331 + 409, 283, true);
    d1_play5 = createObject("button5_49,671.png", dream_1_quiz, 331 + 49, 48, true);
    d1_play6 = createObject("button6_401,681.png", dream_1_quiz, 331 + 401, 38, true);
    exit_d1_quiz = createObject("exit.png", dream_1_quiz, 1000, 38, true);
    scaleObject(exit_d1_quiz, 0.3f);

    //dream1 stage2
    d1_s2_computer = createObject("dream_1_s2_computer_858,355.png", dream_1_lab, 858, 364, true);
    d1_s2_drawer = createObject("dream_1_s2_drawer_1080.410.png", dream_1_lab, 1080, 309, true);
    d1_s2_machine = createObject("dream_1_s2_machine_110,416.png", dream_1_lab, 110, 303, true);
    door_d1_s2 = createObject("exit.png", dream_1_lab, 600, 20, true);
    scaleObject(door_d1_s2, 0.3f);

    //--------------------------------------------------------------------------------

    lock_k = createObject("잠금화면분할_k1.png", scene2_k, 957, 279, true);
    black_k = createObject("검정_k.png", scene1_k, 947, 289, true);
    note_k = createObject("쪽지_k.png", scene1_k, 1175, 360, true);
    scaleObject(note_k, 0.7f);
    note1_k = createObject("쪽지_k.png", scene2_k, 1175, 360, true);
    scaleObject(note1_k, 0.7f);
    note2_k = createObject("쪽지_k.png", scene3_k, 1170, 360, true);
    scaleObject(note2_k, 0.7f);
    left_k = createObject("왼쪽화살표.png", scene5_k, 10, 10, true);
    scaleObject(left_k, 0.2f);
    wmed1_k = createObject("초록물약.png", scene4_k, 690, 240, false);
    hole_k = createObject("구멍.jpg", scene4_k, 609, 139, true);
    machine1_k = createObject("기계분할.jpg", scene4_k, 894, 181, true);
    machine2_k = createObject("기계분할.jpg", scene5_k, 894, 181, true);
    mem1_k = createObject("메모.png", scene4_k, 237, 162, true);
    scaleObject(mem1_k, 0.4f);
    mem_k = createObject("메모.png", scene5_k, 237, 162, true);
    scaleObject(mem_k, 0.4f);
    startbutton = createObject("playbutton.png", initScene[2], 567, 23, true);
    scaleObject(startbutton, 1.5f);
}

void sound_create() {
    //main 효과음
    chest_s = createSound("상자.mp3");
    paper_s = createSound("종이.mp3");
    locker_s = createSound("사물함.mp3");
    machine_s = createSound("자판기.mp3");
    //-----------------------------------------------------
     //intro 
    intro_BGM = createSound("Intro_BGM.mp3");

    //main
    main_BGM = createSound("Main_BGM.mp3");

    //dream1 메인
    dream1_BGM = createSound("d1_BGM_1.mp3");
    dream1_BGM_2 = createSound("d1_BGM_2.mp3");

    //dream1 악기
    d1_1 = createSound("1.mp3");
    d1_2 = createSound("2.mp3");
    d1_3 = createSound("3.mp3");
    d1_4 = createSound("4.mp3");
    d1_5 = createSound("5.mp3");
    d1_6 = createSound("6.mp3");

    //dream1 좀비
    zombie1 = createSound("Zombie1.mp3");
    zombie2 = createSound("Zombie2.mp3");
    zombie3 = createSound("Zombie3.mp3");

    //dream1 기타
    dream_1_door = createSound("dream_1_door.mp3");

    //dream2 
    dream2_BGM = createSound("d2_BGM.mp3");

    //main3
    machines_k = createSound("기계소리.mp3");
    crack_k = createSound("나무부서지는소리.mp3");
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    defineCombination(potion2_s, wmed1_k, potion4_s);
    defineCombination(potion1_s, potion4_s, potion5_s);
    if (object == Scene1_s) {
        if (x > 150 && x < 200 && y > 300 && y < 400) {
            playSound(machine_s);
            if (get_potion_1 == true) {
                pickObject(potion1_s);
                showMessage("물약을 얻었다.");
                get_potion_1 = false;
            }
            else {
                showMessage("물약이 있었던 자리다.");
            }
        }
        if (x > 970 && x < 1170 && y> 400 && y < 480) {
            showImageViewer("칠판문제.png");
            showMessage("위 네 개의 문양 다음에 올 문양을 아래 네개 중에서 골라라. 순서대로 1, 2, 3, 4번이다.");
        }
        if (object == Scene1_s) {
            if (x > 844 && x < 850 && y > 393 && y < 410) {
                if (dream_1_lock == true) showMessage("뭔가 보인다.");
                else {
                    if (get_potion_2 == true) {
                        pickObject(potion2_s);
                        showMessage("물약을 얻었다.\n\"두번째 밤이 끝나고 가장 긴 빛이 가리키는 곳을 찾아라\"");
                        get_potion_2 = false;
                    }
                    else {
                        showMessage("물약이 있었던 자리다.\n\"두번째 밤이 끝나고 가장 긴 빛이 가리키는 곳을 찾아라\"");
                    }
                }
            }
        }
        if (x > 550 && x < 870 && y > 100 && y < 220) {
            if (getHandObject() == glasses_s) {
                showImageViewer("꿈문제.png");
                playSound(paper_s);
            }
            else showMessage("글씨가 작아서 잘 보이지 않는다.");
        }
    }
    else if (object == Scene2_s) {
        if (x > 300 && x < 360 && y > 450 && y < 500) {
            showMessage("시계가 반대로 되어 있다.");
        }
        if (x > 920 && x < 1080 && y > 80 && y < 150) {
            showImageViewer("사물함문제.png");
            showMessage("옆에도 종이가 있다.");
            playSound(paper_s);
        }
        if (x > 1090 && x < 1210 && y > 70 && y < 110) {
            showImageViewer("문제힌트1.png");
            playSound(paper_s);
        }
        if (x > 610 && x < 640 && y < 380 && y > 350) {
            showMessage("1111을 따라가라");
            playSound(locker_s);
        }
        if (x > 710 && x < 730 && y < 380 && y > 350) {
            showMessage("1101을 따라가라");
            playSound(locker_s);
        }
        if (x > 710 && x < 730 && y < 340 && y > 315) {
            if (real_1_lock == true) {
                showMessage("상자를 열어보자.");
                playSound(locker_s);
            }
            else {
                playSound(locker_s);
                showKeypad("32357", ask_board_s);
            }
        }
        if (x > 645 && x < 675 && y < 300 && y > 270) {
            showMessage("1001을 따라가라");
            playSound(locker_s);
        }
        if (x > 600 && x < 650 && y > 200 && y < 250) {
            if (real_1_lock == true) {
                showMessage("상자에 1111이 적혀있다.");
                showKeypad("1478", ask_locker_s);
            }
            else {
                showMessage("칠판 + 1001번 사물함");
            }
        }
    }
    else if (object == right_s) enterScene(scene2_s);
    else if (object == left_s) enterScene(scene1_s);
    else if (object == right_s2) {
        if (holecheck_k == 1) {
            enterScene(scene5_k);
        }
        else enterScene(scene4_k);
    }

    else if (object == left_s2) enterScene(scene2_s);

    else if (object == keypad_dream_s) showKeypad("dream", ask_dream_s);    //맞추면 꿈2
    else if (object == glasses_s) {
        pickObject(glasses_s);
        showMessage("안경을 주웠다.");
    }
    //-------------------------------------------------------------------------
    //음악문제
    else if (object == d1_puzzle) {
        enterScene(dream_1_quiz);
        showMessage("경고:: 기계의 노후화로 빠르게 버튼을 눌렀을 경우, 소리가 안날 수 있음. \n 그래도 버튼은 눌러진 것으로 판단됨.");
    }
    else if (object == d1_play1) {
        playSound(d1_1);
        if (music_d1 == 7) {
            music_d1 += 1;
        }
        else if (music_d1 == 8) {
            music_d1 += 1;
            stopSound(dream1_BGM);
            playSound(dream1_BGM_2, true);
            enterScene(dream_1_main);
            showMessage("음악이 울려퍼진다 \n 좀비들을 진정시킬 수 있을까?");
            dream1_quiz = false;
        }
        else if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 0 || music_d12 == 1) {
                music_d12 += 1;
            }
            else if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    else if (object == d1_play2) {
        playSound(d1_2);
        if (music_d1 == 0 || music_d1 == 6) {
            music_d1 += 1;
        }
        else if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 2) {
                music_d12 += 1;
            }
            else if (music_d12 == 8) {
                music_d12 += 1;
                dreamcheck1_k = 1;
                out_dream_1 = createTimer(0.f);
                startTimer(out_dream_1);
            }
            else if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    else if (object == d1_play3) {
        playSound(d1_3);
        if (music_d1 == 1 || music_d1 == 4) {
            music_d1 += 1;
        }
        else if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 4 || music_d12 == 7) {
                music_d12 += 1;
            }
            else if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    else if (object == d1_play4) {
        playSound(d1_4);
        if (music_d1 == 2) {
            music_d1 += 1;
        }
        else if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 6) {
                music_d12 += 1;
            }
            else if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    else if (object == d1_play5) {
        playSound(d1_5);
        if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    else if (object == d1_play6) {
        playSound(d1_6);
        if (music_d1 == 3 || music_d1 == 5) {
            music_d1 += 1;
        }
        else if (music_d1 == 9) {
            //퀴즈2
            if (music_d12 == 3 || music_d12 == 5) {
                music_d12 += 1;
            }
            else if (music_d12 == 9) {

            }
            else {
                music_d12 = 0;
            }
        }
        else {
            music_d1 = 0;
        }
    }
    // dream1
    else if (object == d1_door) {
        if (dream1_quiz == true) {
            //철창브금
            playSound(zombie1);
            showMessage("철창밖에 좀비들의 소리가 들린다. \n 어떻게 진정시키지?");
        }
        else {
            if (dream1_door == true) {
                playSound(dream_1_door);
                showMessage("철창을 열었다");
                dream1_door = false;
            }
            else {
                enterScene(dream_1_lab);
            }
        }
    }
    else if (object == d1_hint) {
        showImageViewer("oracion_sheet.png");
        showMessage("이거라면 좀비들을 진정시킬 수 있지 않을까? \n 이걸 어떻게 연주하지..?");
    }
    else if (object == exit_d1_quiz) {
        enterScene(dream_1_main);
    }
    //dream1 stage2
    else if (object == door_d1_s2) {
        enterScene(dream_1_main);
    }
    else if (object == d1_s2_computer) {
        showMessage("선율을 반대로 연주하라");
    }
    else if (object == d1_s2_drawer) {
        showImageViewer("dream_1_s2_paper.png");
    }
    else if (object == d1_s2_machine) {
        showMessage("수 많은 기계들이 작동하고 있다.");
    }


    //-------------------------------------------------------------------------

    else if (object == startbutton) {
    //로딩창
        enterScene(initScene_loading);
        loading = createTimer(3.f);
        showTimer(loading);
        hideTimer();
        startTimer(loading);

    }
    else if (object == left_k)
        enterScene(scene2_s);
    else if (object == note_k) {
        showImageViewer("쪽지확대본_k.png");
    }
    else if (object == black_k) {
        enterScene(scene2_k);
    }
    else  if (object == note1_k) {
        showImageViewer("쪽지확대본_k.png");
    }
    else  if (object == note2_k) {
        showImageViewer("쪽지확대본_k.png");
    }
    else if (object == lock_k) {
        if (closed_k == true) {
            showKeypad("52469", lock_k);
        }

    }
    else if (object == hole_k) {
        if (dreamcheck_k == 1) {
            playSound(crack_k);
            holecheck_k = 1;
            enterScene(scene5_k);
            showMessage("물약을 얻었다");
            pickObject(wmed1_k);
        }
    }
    else if (object == machine1_k) {
        if (closed1_k == true) {
            showKeypad("72495", machine1_k);
        }
        else if (closed1_k == false) {
            if (getHandObject() == potion5_s) {
                k1_k = 1;
                srand((unsigned int)time(NULL));
                timer3_k = createTimer();
                setTimer(timer3_k, animationTime);
                startTimer(timer3_k);
            }
            else {
                showMessage("무엇인가를 놓을 수 있도록 되어있다.");
            }
        }
    }
    else if (object == machine2_k) {
        if (closed1_k == true) {
            showKeypad("72495", machine1_k);
        }
        else if (closed1_k == false) {
            if (getHandObject() == potion5_s) {
                k1_k = 1;
                srand((unsigned int)time(NULL));
                timer3_k = createTimer();
                setTimer(timer3_k, animationTime);
                startTimer(timer3_k);
            }
            else {
                showMessage("무엇인가를 놓을 수 있도록 되어있다.");
            }
        }
    }
    else if (object == mem1_k) {
        playSound(paper_s);
        showImageViewer("메모 확대본.png");
    }
    else if (object == mem_k) {
        playSound(paper_s);
        showImageViewer("메모 확대본.png");
    }

}

void timerCallback(TimerID timer)
{
    if (timer == timer1_k) {
        dreamcheck_k = 1;
        k_k = 1.0f;
        hideTimer();
        stopTimer(timer1_k);
        srand((unsigned int)time(NULL));
        setTimer(timer1_k, animationTime);
        timer2_k = createTimer();
        setTimer(timer2_k, animationTime);
        startTimer(timer2_k);
    }
    else if (num_k == 5) {
        //브금 바꾸기 dream2----main
        stopSound(dream2_BGM);
        playSound(main_BGM, true);
        if (holecheck_k == 1) {
            enterScene(scene5_k);
            if (h_k < 1.5) {
                h_k = h_k + 0.2f;
                setSceneLight(scene5_k, h_k);
                if (h_k > 1.2) {
                    num_k = 0;
                }
            }
        }
        else if (holecheck_k == 0) {
            enterScene(scene4_k);
            if (h_k < 1.5) {
                h_k = h_k + 0.2f;
                setSceneLight(scene4_k, h_k);
                if (h_k > 1.2) {
                    num_k = 0;
                }
            }
        }

    }
    else if (k_k > 0) {
        setSceneLight(scene1_k, k_k);
        num_k++;
        k_k = k_k - 0.22f;
    }
    else if (num1_k == 5) {
        enterScene(scene6_k);
        //브금 바꾸기 main----ending
        stopSound(main_BGM);
        playSound(intro_BGM, true);

        if (h1_k < 1.5) {
            h1_k = h1_k + 0.05f;
            setSceneLight(scene6_k, h1_k);
            if (h1_k > 1.2) {
                num1_k = 0;
            }
        }
    }
    else if (k1_k > 0) {
        setSceneLight(scene5_k, k1_k);
        num1_k++;
        k1_k = k1_k - 0.05f;
    }

    else if (timer == timer1_s) {
        s1_s = 1.0f;
        hideTimer();
        stopTimer(timer1_s);
        srand((unsigned int)time(NULL));
        setTimer(timer1_s, animationTime);
        timer2_s = createTimer();
        setTimer(timer2_s, animationTime);
        startTimer(timer2_s);
    }

    else if (num_s == 5) {
        enterScene(scene1_k);
        //브금 바꾸기 main---dream2
        stopSound(main_BGM);
        playSound(dream2_BGM, true);

        if (s2_s < 1.5) {
            s2_s = s2_s + 0.2f;
            setSceneLight(scene1_k, s2_s);
            if (s2_s > 1.2) {
                num_s = 0;
            }
        }
    }
    else if (s1_s > 0) {
        setSceneLight(scene1_k, s1_s);
        num_s++;
        s1_s = s1_s - 0.22f;
    }
    //로딩창
    else if (timer == loading) {
        stopSound(intro_BGM);
        stopTimer(loading);
        playSound(main_BGM, true);
        enterScene(scene1_s);
    }
    //성수랑 연결부분함수 -- 변수 go_dream_1
    else if (timer == timer3_s) {
        s3_s = 1.0f;
        hideTimer();
        stopTimer(timer3_s);
        srand((unsigned int)time(NULL));
        setTimer(timer3_s, animationTime);
        timer4_s = createTimer();
        setTimer(timer4_s, animationTime);
        startTimer(timer4_s);
    }
    else if (go_dream_1 == 5) {
        enterScene(dream_1_main);
        //브금 바꾸기 main-----dream1
        stopSound(main_BGM);
        playSound(dream1_BGM, true);

        if (dream1_light < 1.5) {
            dream1_light = dream1_light + 0.05f;
            setSceneLight(dream_1_main, dream1_light);
            if (dream1_light > 1.2) {
                go_dream_1 = 0;
            }
        }
    }
    else if (s3_s > 0) {
        setSceneLight(dream_1_main, s3_s);
        go_dream_1++;
        s3_s = s3_s - 0.05f;
    }

    //Dream1에서 Main으로
    else if (timer == out_dream_1) {
        g1 = 1.0f;
        hideTimer();
        stopTimer(out_dream_1);
        srand((unsigned int)time(NULL));
        setTimer(out_dream_1, animationTime);
        out_dream_12 = createTimer();
        setTimer(out_dream_12, animationTime);
        startTimer(out_dream_12);
    }
    else if (exit_dream_1 == 5) {
        enterScene(scene1_s);
        //브금 바꾸기 dream1-----main
        stopSound(dream1_BGM_2);
        playSound(main_BGM, true);

        if (main_light < 2.5) {
            main_light = main_light + 0.05f;
            setSceneLight(scene1_s, main_light);
            if (main_light > 1.2) {
                exit_dream_1 = 0;
            }
        }
    }
    else if (g1 > 0) {
        setSceneLight(dream_1_main, g1);
        exit_dream_1++;
        g1 = g1 - 0.05f;
    }

    if (mixcount > 0) {
        --mixcount;
        enterScene(initScene[k]);
        k++;
        setTimer(timerS, animation);
        startTimer(timerS);
    }

    setTimer(timer_animation, animationTime);
    startTimer(timer_animation);

    setTimer(timer_animation, animationTime);
    startTimer(timer_animation);
    setTimer(timer4_s, animationTime);
    startTimer(timer4_s);
    setTimer(out_dream_12, animationTime);
    startTimer(out_dream_12);
    setTimer(timer2_s, animationTime);
    startTimer(timer2_s);
    setTimer(timer2_k, animationTime);
    startTimer(timer2_k);
    setTimer(timer3_k, animationTime);
    startTimer(timer3_k);
}

void objectCallback(ObjectID object, EventID event) {
    if (object == ask_locker_s) {
        if (event == EventID::EVENT_KEYPAD) {
            playSound(chest_s);
            showMessage("상자가 열렸다!");
            real_1_lock = false;
        }
    }
    if (object == ask_board_s) {                    //꿈1 들어감
        if (event == EventID::EVENT_KEYPAD) {
            if (dreamcheck1_k == 0) {
                showObject(keypad_dream_s);
                showObject(glasses_s);
                dream_1_lock = false;
                timer3_s = createTimer(0.f);
                startTimer(timer3_s);
            }
            else {
                showMessage("한번 꾼 꿈은 다시 꿀 수 없지");
            }
        }
    }
    if (object == ask_dream_s) {                    //꿈2 들어감.
        if (event == EventID::EVENT_KEYPAD) {
            if (dreamcheck_k == 0) {
                timer1_s = createTimer(0.f);
                startTimer(timer1_s);
            }
            else {
                showMessage("한번 꾼 꿈은 다시 꿀 수 없지");
            }
        }
    }
    //----------------------------------------------------------------------

    if (object == lock_k) {
        if (event == EventID::EVENT_KEYPAD) {
            closed_k = false;
            enterScene(scene3_k);
            timer1_k = createTimer(10.f);
            showTimer(timer1_k);
            startTimer(timer1_k);
        }
    }
    if (object == machine1_k) {
        if (event == EventID::EVENT_KEYPAD) {
            playSound(machines_k);
            showMessage("장치가 가동되기 시작했다.");
            closed1_k = false;
        }
    }
}

int main() {
    setMouseCallback(mouseCallback);
    setObjectCallback(objectCallback);
    setTimerCallback(timerCallback);
    setSceneCallback(sceneCallback);
    mix();
    game_start();
    object_create();
    sound_create();
    startGame(scene_p);
}