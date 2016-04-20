package sample;

import javafx.animation.AnimationTimer;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;

/**
 * Created by katrin on 2/29/16.
 */
public class House implements Serializable {
    public static Image picture_wall;

    public KeyProccessing k;
    public ArrayList<DrawItems> items;
    public Canvas canvas;
    public GraphicsContext gc;

    public int[][] room_level_1;



    public void initialize()  throws IOException{
        canvas.setFocusTraversable(true);

        k = new KeyProccessing(canvas);
        items = new ArrayList<DrawItems>();
        picture_wall = new Image("/images/wall.png");

        items.add(new MouseJerry(50, 50, k));
        items.add(new CatTom(500, 100));
        items.add(new Cheese(400, 130));
        items.add(new Cheese(680, 400));
        items.add(new Cheese(300, 700));
        items.add(new Hole(100, 700));
        items.add(new Clock(90, 370));
        items.add(new VacumCleaner(270, 600));
        items.add(new Flower(270, 60));

        items.add(new VerticalWAlls(90, 10, 15));
        items.add(new VerticalWAlls(200, 200, 20));
        items.add(new VerticalWAlls(550, 85, 25));
        items.add(new VerticalWAlls(710, 85, 25));
        items.add(new VerticalWAlls(0, 0, 60));
        items.add(new VerticalWAlls(Constants.MAP_WIDTH - 22, 0 , 60));


        items.add(new HorizontalWalls(10, 500, 9));
        items.add(new HorizontalWalls(200, 630, 24));
        items.add(new HorizontalWalls(0, Constants.MAP_HEIGHT - 22, 62));
        items.add(new HorizontalWalls(0, 0, 62));

        gc = canvas.getGraphicsContext2D();

        //main loop
        new AnimationTimer() {
            public void handle(long startNanoTime) {
                make_map(gc);
                try {
                    check(k);

                } catch (IOException e){
                }
                for (DrawItems obj : items) {
                    obj.draw(gc);
                }

                Iterator<DrawItems> it = items.iterator();

                while (it.hasNext()) {
                    DrawItems current = it.next();

                    if (current instanceof IMoveble) {
                        ((IMoveble) current).Move(items);
                    }
                }

                it = items.iterator();

                while (it.hasNext()) {
                    DrawItems current = it.next();

                    if (current instanceof IEatable) {
                        if (((IEatable) current).isEaten() == true){
                            it.remove();
                        }
                    }
                }

                long currentNanoTime = System.nanoTime();
                while (System.nanoTime() - startNanoTime < 200000) {
                }
            }
        }.start();


    }

    public void make_map(GraphicsContext gc) {
        gc.setFill(Color.SKYBLUE);
        gc.fillRect(0, 0, Constants.MAP_WIDTH, Constants.MAP_HEIGHT);
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
                load();
                break;
            }
        }
    }

    public void save() throws IOException {
        FileOutputStream fos = new FileOutputStream("out.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(items);
        oos.flush();
        oos.close();
        fos.close();
    }

    public void load() throws IOException {
        FileInputStream fis = new FileInputStream("out.txt");
        ObjectInputStream oin = new ObjectInputStream(fis);
        try{
            items = (ArrayList<DrawItems>) oin.readObject();
        } catch (Exception e){
            System.out.println(e);
        }
        for (Object i : items){
            if( i instanceof MouseJerry){
                ((MouseJerry) i).set_keypr(k);
                break;
            }
        }
        fis.close();
        oin.close();
    }
}