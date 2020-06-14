#include <bangtal.h>
#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

SceneID scene1_s;                                  //ù��°ȭ��
SceneID scene2_s;                                  //�ι�°ȭ��
ObjectID Scene1_s, Scene2_s;                        //���콺�ݹ� ���� ( ��� )
ObjectID potion1_s, potion2_s, potion3_s;           //���� -- potion3_s=wmed1_k
ObjectID potion4_s, potion5_s;                      //�ռ� ����
ObjectID ask_locker_s, ask_board_s, ask_dream_s;    //����
ObjectID left_s, right_s, left_s2, right_s2;                           //ȭ��ǥ
ObjectID keypad_dream_s;                            //��2���� Ű�е�
ObjectID glasses_s;                                 //��2 �������� �Ȱ�
TimerID timer1_s, timer2_s, timer3_s, timer4_s;
SoundID paper_s, chest_s, locker_s, machine_s, hint_s;
float s1_s = 0.0f;
int num_s = 0;
float s2_s = 0.0f;
float s3_s = 0.0f;


bool real_1_lock = true;                            //���� ���� ���

bool dream_1_lock = true;                           //ù ��° �� ���� ����2 ���̱�

bool dream_2_lock = true;                           //�� ��° ��

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
//�Ǳ�
d1_play1, d1_play2, d1_play3, d1_play4, d1_play5, d1_play6;
SoundID intro_BGM, main_BGM, dream1_BGM, dream1_BGM_2, dream_1_door, dream2_BGM,
d1_1, d1_2, d1_3, d1_4, d1_5, d1_6,
zombie1, zombie2, zombie3;
TimerID loading, timer_animation, go_dream_1, out_dream_1, out_dream_12, exit_dream_1;
//Ÿ�̸� �ִϸ��̼�
float dream1_light = 0.0f;
float main_light = 0.0f;
float g1 = 0.0f;
//����
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
    //���� 1,2
    scene1_s = createScene("room1", "���1.jpg");
    scene2_s = createScene("room2", "���2.jpg");
    //--------------------------------------------------
    //�ε�
    initScene_loading = createScene(" ", "3_loading.png");
    //��1
    dream_1_main = createScene(" ", "dream_1_stage1.png");
    dream_1_quiz = createScene(" ", "dream_1_button_all.png");
    dream_1_lab = createScene(" ", "dream_1_stage2.png");

    //------------------------------------------------------
    //��2, ����3
    scene1_k = createScene(" ", "main_k2.png");
    scene2_k = createScene(" ", "���ȭ��_k1.png");
    scene3_k = createScene(" ", "���յ�_k.png");
    scene4_k = createScene("room3", "������ȭ��.jpg");
    scene5_k = createScene("room3", "����.png");
    scene6_k = createScene(" ", "����.png");
    scene_p = createScene(" ", "1.png");
}

void object_create() {
    Scene1_s = createObject("���1.jpg", scene1_s, 0, 0, true);
    Scene2_s = createObject("���2.jpg", scene2_s, 0, 0, true);

    ask_locker_s = createObject("�繰�Թ���.png");
    ask_board_s = createObject("ĥ�ǹ���.png");

    ask_dream_s = createObject("�޹���.png");
    keypad_dream_s = createObject("Ű�е�.png", scene1_s, 823, 257, false);    //��1���� ������ true

    potion1_s = createObject("����1.png");
    potion2_s = createObject("����2.png");
    potion4_s = createObject("����4.png");
    potion5_s = createObject("����5.png");

    glasses_s = createObject("�Ȱ�.png", scene1_s, 160, 10, false);
    hint_s = createObject("������Ʈ1.png");

    right_s = createObject("������ȭ��ǥ.png", scene1_s, 1150, 10, true);
    left_s = createObject("����ȭ��ǥ.png", scene2_s, 10, 10, true);
    right_s2 = createObject("������ȭ��ǥ.png", scene2_s, 1150, 10, true);
    left_s2 = createObject("����ȭ��ǥ.png", scene4_k, 10, 10, true);

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

    lock_k = createObject("���ȭ�����_k1.png", scene2_k, 957, 279, true);
    black_k = createObject("����_k.png", scene1_k, 947, 289, true);
    note_k = createObject("����_k.png", scene1_k, 1175, 360, true);
    scaleObject(note_k, 0.7f);
    note1_k = createObject("����_k.png", scene2_k, 1175, 360, true);
    scaleObject(note1_k, 0.7f);
    note2_k = createObject("����_k.png", scene3_k, 1170, 360, true);
    scaleObject(note2_k, 0.7f);
    left_k = createObject("����ȭ��ǥ.png", scene5_k, 10, 10, true);
    scaleObject(left_k, 0.2f);
    wmed1_k = createObject("�ʷϹ���.png", scene4_k, 690, 240, false);
    hole_k = createObject("����.jpg", scene4_k, 609, 139, true);
    machine1_k = createObject("������.jpg", scene4_k, 894, 181, true);
    machine2_k = createObject("������.jpg", scene5_k, 894, 181, true);
    mem1_k = createObject("�޸�.png", scene4_k, 237, 162, true);
    scaleObject(mem1_k, 0.4f);
    mem_k = createObject("�޸�.png", scene5_k, 237, 162, true);
    scaleObject(mem_k, 0.4f);
    startbutton = createObject("playbutton.png", initScene[2], 567, 23, true);
    scaleObject(startbutton, 1.5f);
}

void sound_create() {
    //main ȿ����
    chest_s = createSound("����.mp3");
    paper_s = createSound("����.mp3");
    locker_s = createSound("�繰��.mp3");
    machine_s = createSound("���Ǳ�.mp3");
    //-----------------------------------------------------
     //intro 
    intro_BGM = createSound("Intro_BGM.mp3");

    //main
    main_BGM = createSound("Main_BGM.mp3");

    //dream1 ����
    dream1_BGM = createSound("d1_BGM_1.mp3");
    dream1_BGM_2 = createSound("d1_BGM_2.mp3");

    //dream1 �Ǳ�
    d1_1 = createSound("1.mp3");
    d1_2 = createSound("2.mp3");
    d1_3 = createSound("3.mp3");
    d1_4 = createSound("4.mp3");
    d1_5 = createSound("5.mp3");
    d1_6 = createSound("6.mp3");

    //dream1 ����
    zombie1 = createSound("Zombie1.mp3");
    zombie2 = createSound("Zombie2.mp3");
    zombie3 = createSound("Zombie3.mp3");

    //dream1 ��Ÿ
    dream_1_door = createSound("dream_1_door.mp3");

    //dream2 
    dream2_BGM = createSound("d2_BGM.mp3");

    //main3
    machines_k = createSound("���Ҹ�.mp3");
    crack_k = createSound("�����μ����¼Ҹ�.mp3");
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    defineCombination(potion2_s, wmed1_k, potion4_s);
    defineCombination(potion1_s, potion4_s, potion5_s);
    if (object == Scene1_s) {
        if (x > 150 && x < 200 && y > 300 && y < 400) {
            playSound(machine_s);
            if (get_potion_1 == true) {
                pickObject(potion1_s);
                showMessage("������ �����.");
                get_potion_1 = false;
            }
            else {
                showMessage("������ �־��� �ڸ���.");
            }
        }
        if (x > 970 && x < 1170 && y> 400 && y < 480) {
            showImageViewer("ĥ�ǹ���.png");
            showMessage("�� �� ���� ���� ������ �� ������ �Ʒ� �װ� �߿��� ����. ������� 1, 2, 3, 4���̴�.");
        }
        if (object == Scene1_s) {
            if (x > 844 && x < 850 && y > 393 && y < 410) {
                if (dream_1_lock == true) showMessage("���� ���δ�.");
                else {
                    if (get_potion_2 == true) {
                        pickObject(potion2_s);
                        showMessage("������ �����.\n\"�ι�° ���� ������ ���� �� ���� ����Ű�� ���� ã�ƶ�\"");
                        get_potion_2 = false;
                    }
                    else {
                        showMessage("������ �־��� �ڸ���.\n\"�ι�° ���� ������ ���� �� ���� ����Ű�� ���� ã�ƶ�\"");
                    }
                }
            }
        }
        if (x > 550 && x < 870 && y > 100 && y < 220) {
            if (getHandObject() == glasses_s) {
                showImageViewer("�޹���.png");
                playSound(paper_s);
            }
            else showMessage("�۾��� �۾Ƽ� �� ������ �ʴ´�.");
        }
    }
    else if (object == Scene2_s) {
        if (x > 300 && x < 360 && y > 450 && y < 500) {
            showMessage("�ð谡 �ݴ�� �Ǿ� �ִ�.");
        }
        if (x > 920 && x < 1080 && y > 80 && y < 150) {
            showImageViewer("�繰�Թ���.png");
            showMessage("������ ���̰� �ִ�.");
            playSound(paper_s);
        }
        if (x > 1090 && x < 1210 && y > 70 && y < 110) {
            showImageViewer("������Ʈ1.png");
            playSound(paper_s);
        }
        if (x > 610 && x < 640 && y < 380 && y > 350) {
            showMessage("1111�� ���󰡶�");
            playSound(locker_s);
        }
        if (x > 710 && x < 730 && y < 380 && y > 350) {
            showMessage("1101�� ���󰡶�");
            playSound(locker_s);
        }
        if (x > 710 && x < 730 && y < 340 && y > 315) {
            if (real_1_lock == true) {
                showMessage("���ڸ� �����.");
                playSound(locker_s);
            }
            else {
                playSound(locker_s);
                showKeypad("32357", ask_board_s);
            }
        }
        if (x > 645 && x < 675 && y < 300 && y > 270) {
            showMessage("1001�� ���󰡶�");
            playSound(locker_s);
        }
        if (x > 600 && x < 650 && y > 200 && y < 250) {
            if (real_1_lock == true) {
                showMessage("���ڿ� 1111�� �����ִ�.");
                showKeypad("1478", ask_locker_s);
            }
            else {
                showMessage("ĥ�� + 1001�� �繰��");
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

    else if (object == keypad_dream_s) showKeypad("dream", ask_dream_s);    //���߸� ��2
    else if (object == glasses_s) {
        pickObject(glasses_s);
        showMessage("�Ȱ��� �ֿ���.");
    }
    //-------------------------------------------------------------------------
    //���ǹ���
    else if (object == d1_puzzle) {
        enterScene(dream_1_quiz);
        showMessage("���:: ����� ����ȭ�� ������ ��ư�� ������ ���, �Ҹ��� �ȳ� �� ����. \n �׷��� ��ư�� ������ ������ �Ǵܵ�.");
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
            showMessage("������ ��������� \n ������� ������ų �� ������?");
            dream1_quiz = false;
        }
        else if (music_d1 == 9) {
            //����2
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
            //����2
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
            //����2
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
            //����2
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
            //����2
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
            //����2
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
            //öâ���
            playSound(zombie1);
            showMessage("öâ�ۿ� ������� �Ҹ��� �鸰��. \n ��� ������Ű��?");
        }
        else {
            if (dream1_door == true) {
                playSound(dream_1_door);
                showMessage("öâ�� ������");
                dream1_door = false;
            }
            else {
                enterScene(dream_1_lab);
            }
        }
    }
    else if (object == d1_hint) {
        showImageViewer("oracion_sheet.png");
        showMessage("�̰Ŷ�� ������� ������ų �� ���� ������? \n �̰� ��� ��������..?");
    }
    else if (object == exit_d1_quiz) {
        enterScene(dream_1_main);
    }
    //dream1 stage2
    else if (object == door_d1_s2) {
        enterScene(dream_1_main);
    }
    else if (object == d1_s2_computer) {
        showMessage("������ �ݴ�� �����϶�");
    }
    else if (object == d1_s2_drawer) {
        showImageViewer("dream_1_s2_paper.png");
    }
    else if (object == d1_s2_machine) {
        showMessage("�� ���� ������ �۵��ϰ� �ִ�.");
    }


    //-------------------------------------------------------------------------

    else if (object == startbutton) {
    //�ε�â
        enterScene(initScene_loading);
        loading = createTimer(3.f);
        showTimer(loading);
        hideTimer();
        startTimer(loading);

    }
    else if (object == left_k)
        enterScene(scene2_s);
    else if (object == note_k) {
        showImageViewer("����Ȯ�뺻_k.png");
    }
    else if (object == black_k) {
        enterScene(scene2_k);
    }
    else  if (object == note1_k) {
        showImageViewer("����Ȯ�뺻_k.png");
    }
    else  if (object == note2_k) {
        showImageViewer("����Ȯ�뺻_k.png");
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
            showMessage("������ �����");
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
                showMessage("�����ΰ��� ���� �� �ֵ��� �Ǿ��ִ�.");
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
                showMessage("�����ΰ��� ���� �� �ֵ��� �Ǿ��ִ�.");
            }
        }
    }
    else if (object == mem1_k) {
        playSound(paper_s);
        showImageViewer("�޸� Ȯ�뺻.png");
    }
    else if (object == mem_k) {
        playSound(paper_s);
        showImageViewer("�޸� Ȯ�뺻.png");
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
        //��� �ٲٱ� dream2----main
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
        //��� �ٲٱ� main----ending
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
        //��� �ٲٱ� main---dream2
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
    //�ε�â
    else if (timer == loading) {
        stopSound(intro_BGM);
        stopTimer(loading);
        playSound(main_BGM, true);
        enterScene(scene1_s);
    }
    //������ ����κ��Լ� -- ���� go_dream_1
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
        //��� �ٲٱ� main-----dream1
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

    //Dream1���� Main����
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
        //��� �ٲٱ� dream1-----main
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
            showMessage("���ڰ� ���ȴ�!");
            real_1_lock = false;
        }
    }
    if (object == ask_board_s) {                    //��1 ��
        if (event == EventID::EVENT_KEYPAD) {
            if (dreamcheck1_k == 0) {
                showObject(keypad_dream_s);
                showObject(glasses_s);
                dream_1_lock = false;
                timer3_s = createTimer(0.f);
                startTimer(timer3_s);
            }
            else {
                showMessage("�ѹ� �� ���� �ٽ� �� �� ����");
            }
        }
    }
    if (object == ask_dream_s) {                    //��2 ��.
        if (event == EventID::EVENT_KEYPAD) {
            if (dreamcheck_k == 0) {
                timer1_s = createTimer(0.f);
                startTimer(timer1_s);
            }
            else {
                showMessage("�ѹ� �� ���� �ٽ� �� �� ����");
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
            showMessage("��ġ�� �����Ǳ� �����ߴ�.");
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