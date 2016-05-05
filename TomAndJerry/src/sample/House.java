package sample;
//http://pastebin.com/K1kWwgke - 1Level
//http://pastebin.com/gF6c96Bt - 2Level
import javafx.animation.AnimationTimer;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 * Created by katrin on 2/29/16.
 */
public class House implements Serializable {
    public static Image t;

    private boolean game_stopped = false;
    public KeyProccessing k;
    public ArrayList<DrawItems> items;
    public GraphicsContext gc;

    @FXML
    public Label score_l;
    public Label count_cheese;
    public Label time_l;
    public Label fps_label;
    public Label game_over;
    public Label win;

    public ImageView pause;
    public ImageView play;
    public ImageView restart;
    public ImageView close;

    public GridPane control_p;
    public Canvas canvas;

    private int fps = 0;
    private long prevFpsNano = 0;

    private SimpleDateFormat sdf;
    private Date curLevelTime;
    private Date finishLevelTime;

    private long show_timeD()
    {
        long diff = finishLevelTime.getTime() - curLevelTime.getTime();
        diff = Math.max(diff, 0);
        Date difference = new Date(diff + 75600000);
        if (diff < 11000)
        {
            time_l.setTextFill(Color.RED);
        }
        time_l.setText("Time: " + sdf.format(difference));
        return diff;
    }

    private void show_fps()
    {
        fps_label.setText(String.format("fps = %d", fps));
        fps = 0;
        prevFpsNano = System.nanoTime();
    }

    private void show_score_l(MouseJerry m)
    {
        score_l.setText(String.format("Score: %d", m.getScore()));
        count_cheese.setText(String.format("Cheese: %d", m.see_cheese(m)));
    }

    private void show_lD() {
        game_over.setVisible(true);
        canvas.setOpacity(0.8);
        game_stopped = true;
    }

    private void show_lWin() {
        win.setVisible(true);
        canvas.setOpacity(0.8);
        game_stopped = true;
    }

    private void stop_pressed(KeyProccessing k)
    {
        HashSet<KeyCode> state = k.retHashSet();
        for (KeyCode key: state)
        {
            if (key == KeyCode.P)
            {
                game_stopped = game_stopped ^ true;
            }
        }
    }

    public void initialize()  throws IOException
    {
        Main lv = new Main();
        canvas.setFocusTraversable(true);
        sdf = new SimpleDateFormat("HH:mm:ss");
        k = new KeyProccessing(canvas);
        items = new ArrayList<DrawItems>();

        if (lv.level1)
        {
            t = new Image("/maps/lev1-1.jpg");
            items.add(new LittleChesse(400, 130));
            items.add(new LittleChesse(185, 300));
            items.add(new Big_cheese(680, 340));
            items.add(new Big_cheese(100, 600));
            items.add(new Big_cheese(1180, 300));
            items.add(new Big_cheese(900, 100));
            items.add(new Big_cheese(1030, 620));

            items.add(new BlackOil(640, 120));
            items.add(new BlackOil(110, 400));
            items.add(new BlackOil(450, 300));
            items.add(new BlackOil(1203, 512));

            items.add(new Hole(1150, 100));
            items.add(new Clock(1000, 200));
            items.add(new Clock(220, 620));
            items.add(new Flower(270, 100));

            items.add(new Mousetrap(600, 600));
            items.add(new MouseJerry(100, 150, k));

            curLevelTime = Calendar.getInstance().getTime();
            long level_time = ((MouseJerry) items.get(items.size() - 1)).life_time;
            finishLevelTime = new Date(Calendar.getInstance().getTime().getTime() + level_time * 1000);

            CatTom cat = new CatTom(200, 620);
            cat.pos.add(new Position(200, 620));
            cat.pos.add(new Position(1100, 620));
            cat.pos.add(new Position(1100, 430));
            cat.pos.add(new Position(330, 430));
            cat.pos.add(new Position(330, 150));
            cat.pos.add(new Position(210, 150));
            items.add(cat);

            items.add(new VerticalWAlls(210, 210, 7));
            items.add(new VerticalWAlls(770, 200, 5));
            items.add(new VerticalWAlls(1080, 10, 10));
            items.add(new VerticalWAlls(1095, 10, 10));
            items.add(new VerticalWAlls(42, 10, 60));
            items.add(new VerticalWAlls(Constants.MAP_WIDTH - 110, 0 , 60));

            items.add(new HorizontalWalls(220, 494, 14));
            items.add(new HorizontalWalls(220, 470, 14));
            items.add(new HorizontalWalls(370, 230, 10));
            items.add(new HorizontalWalls(370, 190, 11));
            items.add(new HorizontalWalls(0, Constants.MAP_HEIGHT - 100, 62));
            items.add(new HorizontalWalls(0, 43, 62));
        } else
        {
            t = new Image("maps/lev1-3.jpg");
            items.add(new LittleChesse(400, 130));
            items.add(new LittleChesse(185, 300));
            items.add(new Big_cheese(680, 340));
            items.add(new Big_cheese(100, 600));
            items.add(new Big_cheese(1180, 300));
            items.add(new Big_cheese(900, 100));
            items.add(new Big_cheese(1030, 620));

            items.add(new BlackOil(110, 400));
            items.add(new BlackOil(450, 300));
            items.add(new BlackOil(1203, 512));

            items.add(new Hole(700, 100));
            items.add(new Clock(1000, 200));
            items.add(new Flower(270, 100));
            items.add(new Flower(1228, 630));

            items.add(new Mousetrap(600, 600));
            items.add(new MouseJerry(100, 600, k));

            curLevelTime = Calendar.getInstance().getTime();
            long level_time = ((MouseJerry) items.get(items.size() - 1)).life_time;
            finishLevelTime = new Date(Calendar.getInstance().getTime().getTime() + level_time * 1000);

            CatTom cat = new CatTom(1230, 50);

            cat.pos.add(new Position(1230, 50));
            cat.pos.add(new Position(1230, 600));
            cat.pos.add(new Position(965, 600));
            cat.pos.add(new Position(965, 125));
            cat.pos.add(new Position(755,125));
            cat.pos.add(new Position(755, 580));
            cat.pos.add(new Position(500, 580));
            cat.pos.add(new Position(500, 180));
            cat.pos.add(new Position(250,180));
            cat.pos.add(new Position(250, 520));
            items.add(cat);

            items.add(new VerticalWAlls(315, 255, 12));
            items.add(new VerticalWAlls(582, 10, 12));
            items.add(new VerticalWAlls(868, 230, 12));
            items.add(new VerticalWAlls(1080, 10, 13));
            items.add(new VerticalWAlls(1095, 10, 13));
            items.add(new VerticalWAlls(42, 10, 60));
            items.add(new VerticalWAlls(Constants.MAP_WIDTH - 110, 0 , 60));

            items.add(new HorizontalWalls(0, Constants.MAP_HEIGHT - 100, 62));
            items.add(new HorizontalWalls(0, 43, 62));
        }

        gc = canvas.getGraphicsContext2D();

        pause.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                canvas.setOpacity(0.7);
                game_stopped = true;
                control_p.setVisible(true);
            }
        });

        play.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>(){
            @Override
            public void handle(MouseEvent event) {
                canvas.setOpacity(1);
                game_over.setVisible(false);
                control_p.setVisible(false);
                win.setVisible(false);

                game_stopped = false;
            }
        });

        restart.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try {
                    canvas.setOpacity(1);
                    win.setVisible(false);
                    game_over.setVisible(false);
                    if (lv.level1) {
                        load("out1.txt");
                    } else
                    {
                        load("out2.txt");
                    }
                    control_p.setVisible(false);
                    game_stopped = false;
                } catch (Exception e){ }
            }
        });

        close.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try {
                    System.exit(0);
                } catch (Exception e){ }
            }
        });

        //main loop
        new AnimationTimer() {
            public void handle(long startNanoTime) {
                make_map(gc);
                curLevelTime = Calendar.getInstance().getTime();
                long temp = show_timeD();
                try {
                    check(k);
                } catch (IOException e){
                }

                stop_pressed(k);

                if (temp == 0) {
                    game_stopped = true;
                    game_over.setVisible(true);
                }
                if (!game_stopped) {
                    Iterator<DrawItems> it = items.iterator();
                    while (it.hasNext()) {
                        DrawItems current = it.next();

                        if (current instanceof IMoveble) {
                            ((IMoveble) current).Move(items);
                        }
                        if (current instanceof MouseJerry) {
                            if (((MouseJerry) current).isDead == true) {
                                show_lD();
                            }
                            if (((MouseJerry) current).getEnd()){
                                //items.remove((MouseJerry) current);
                                show_lWin();
                                game_stopped = true;
                            }
                        }
                    }
                    it = items.iterator();
                    while (it.hasNext()) {
                        DrawItems current = it.next();

                        if (current instanceof IEatable) {
                            if (((IEatable) current).isEaten() == true) {
                                it.remove();
                            }
                        }
                    }
                    long currentNanoTime = System.nanoTime();
                    while (System.nanoTime() - startNanoTime < 200000) {
                    }
                }

                fps++;
                if (Math.abs(prevFpsNano - System.nanoTime()) >= 1000000000) {
                    show_fps();
                }

                for (DrawItems obj : items) {
                    if (obj instanceof MouseJerry){
                        show_score_l((MouseJerry) obj);
                    }
                    obj.draw(gc);
                }
            }
        }.start();


    }

    public void make_map(GraphicsContext gc) {
        gc.drawImage(t, 0, 0, Constants.MAP_WIDTH, Constants.MAP_HEIGHT);
    }


    public void check(KeyProccessing k) throws IOException
    {
        HashSet<KeyCode> temp = k.retHashSet();
        for (KeyCode i : temp){
            if (i == KeyCode.S) {
                save();
                break;
            }
            if(i == KeyCode.L){
                load("out1.txt");
                break;
            }
        }
    }

    public void save() throws IOException {
        FileOutputStream fos = new FileOutputStream("out1.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(items);
        oos.flush();
        oos.close();
        fos.close();
    }

    public void load(String str) throws IOException {
        FileInputStream fis = new FileInputStream(str);
        ObjectInputStream oin = new ObjectInputStream(fis);
        try{
            items = (ArrayList<DrawItems>) oin.readObject();
        } catch (Exception e){
            System.out.println(e);
        }
        for (Object i : items){
            if( i instanceof MouseJerry){
                ((MouseJerry) i).set_keypr(k);
                ((MouseJerry) i).setPicture(1);
                    curLevelTime = Calendar.getInstance().getTime();
                    finishLevelTime = new Date(Calendar.getInstance().getTime().getTime()
                            + ((MouseJerry) i).life_time * 1000);
                break;
            }
        }
        fis.close();
        oin.close();
    }
}