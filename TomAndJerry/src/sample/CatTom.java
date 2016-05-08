package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;
import java.util.ArrayList;

/**
 * Created by katrin on 3/3/16.
 */
public class CatTom extends DrawItems implements IMoveble, Serializable, IEnemy{

    private static CatStrategies.Strategy strategy;

    private transient static int[] dx = {4, 4};
    private transient static int[] dy = { -4, 0};

    private transient static int x_vc = 270;
    private transient static int y_vc = 600;

    private int lastpos;
    private int index_picture;

    public ArrayList<Position> pos;

    private static Image cur_picture;
    private static Image left1, left2;
    private static Image right1, right2;
    private static Image back1, back2;
    private static Image straight1, straight2;

    private static Image rback1, rback2;
    private static Image lback1, lback2;
    private static Image rstraight1, rstraight2;
    private static Image lstraight1, lstraight2;

    public int getLastpos()
    {
        return lastpos;
    }
    public  void setLastpos(int value)
    {
        lastpos = value;
    }

    public CatTom(int x, int y)
    {
        pos = new ArrayList<Position>();
        lastpos = 0;

        setX(x);
        setY(y);
        setCalmStrategy();
        System.out.println("Tom is ready to run for a mouse");

        cur_picture = new Image("/images/cat/cat_left1.png");

        left1 = new Image("/images/cat/cat_left1.png");
        left2 = new Image("/images/cat/cat_left2.png");
        right1 = new Image("/images/cat/cat_right1.png");
        right2 = new Image("/images/cat/cat_right2.png");
        back1 = new Image("/images/cat/cat_back1.png");
        back2 = new Image("/images/cat/cat_back2.png");
        straight1 = new Image("/images/cat/cat_straight1.png");
        straight2 = new Image("/images/cat/cat_straight2.png");

        rback1 = new Image("/images/cat/r_back1.png");
        rback2 = new Image("/images/cat/r_back2.png");
        rstraight1 = new Image("/images/cat/r_straight1.png");
        rstraight2 = new Image("/images/cat/r_straight2.png");
        lback1 = new Image("/images/cat/l_back1.png");
        lback2 = new Image("/images/cat/l_back2.png");
        lstraight1 = new Image("/images/cat/l_straight1.png");
        lstraight2 = new Image("/images/cat/l_straight2.png");
    }


    public void signal(MouseJerry jer)
    {
        double distance = dist(getX(), getY(), jer.getX(), jer.getY());

        if( distance <= 10 )
        {
            System.out.println("Tom see Jerry, start run\n");
        }else
        {
            System.out.println("Tom doesn't see Jerry\n");
        }
    }

    public double dist(int x1, int y1, int x2, int y2)
    {
        return Math.sqrt((double)((x1 - x2) * (x1 - x2)  + (y1 - y2) * (y1 - y2)));
    }


    public void setCalmStrategy() {
        if (!(strategy instanceof CatStrategies.CalmStrategy)) {
            strategy = new CatStrategies.CalmStrategy(this);
        }
    }


    public void setAggressiveStrategy() {
        if (!(strategy instanceof CatStrategies.AggressiveStrategy)) {
            strategy = new CatStrategies.AggressiveStrategy();
        }
    }

    public boolean isFree(int newx, int newy, ArrayList<DrawItems> items) {

        boolean canMove = true;

        int dx[] = {-8, 8, -8, 8};
        int dy[] = {-20, 20, 20, -20};

        for (DrawItems i : items){
            if ( i instanceof IBarrier) {
                int x1 = i.getX();
                int y1 = i.getY();
                int x2 = ((IBarrier) i).getCornerX();
                int y2 = ((IBarrier) i).getCornerY();

                for (int j = 0; j < 4; j++) {
                    int curx = dx[j] + newx;
                    int cury = dy[j] + newy;
                    if (x1 <= curx && curx <= x2 &&
                            y1 <= cury && cury <= y2) {
                        canMove = false;
                    }
                }
            }
        }

        return canMove;
    }

    public void change_picture(int newx, int newy){
        int x = this.getX();
        int y = this.getY();

        if (index_picture <= 7) {
            index_picture++;
            return;
        }

        index_picture = 0;
        if (y == newy && newx > x)
        {
            if (cur_picture == right1){
                cur_picture = right2;
            } else
            {
                cur_picture = right1;
            }
        }

        if (y == newy && newx < x) {
            if (cur_picture == left1) {
                cur_picture = left2;
            } else{
                cur_picture = left1;
            }
        }

        if (x == newx && newy > y) {
            if (cur_picture == straight1) {
                cur_picture = straight2;
            } else
            {
                cur_picture = straight1;
            }
        }

        if (x == newx && newy < y) {
            if (cur_picture == back1 ) {
                cur_picture = back2;
            } else{
                cur_picture = back1;
            }
        }

        if (newx > x && newy > y){
            if (cur_picture == rstraight1) {
                cur_picture = rstraight2;
            } else {
                cur_picture = rstraight1;
            }
        }

        if (newx > x && newy < y) {
            if (cur_picture == rback1){
                cur_picture = rback2;
            } else {
                cur_picture = rback1;
            }
        }

        if (newx < x && newy < y) {
            if (cur_picture == lback1) {
                cur_picture = lback2;
            } else {
                cur_picture = lback1;
            }
        }

        if (newx < x && newy > y) {
            if (cur_picture == lstraight1) {
                cur_picture = lstraight2;
            } else {
                cur_picture = lstraight1;
            }
        }
    }

    public void tryStep(int newx, int newy, ArrayList<DrawItems> items){

        boolean canMove = true;

        int dx[] = {-30, 30, -30, 30};
        int dy[] = {-35, 35, 35, -35};

        for (DrawItems i : items){
            if ( i instanceof IBarrier) {
                int x1 = i.getX();
                int y1 = i.getY();
                int x2 = ((IBarrier) i).getCornerX();
                int y2 = ((IBarrier) i).getCornerY();

                for (int j = 0; j < 4; j++) {
                    int curx = dx[j] + newx;
                    int cury = dy[j] + newy;
                    if (x1 <= curx && curx <= x2 &&
                            y1 <= cury && cury <= y2) {
                        canMove = false;
                    }
                }
            }
        }

        if (canMove) {
            setX(newx);
            setY(newy);
        }
    }

    public void Move(ArrayList<DrawItems> items){
        strategy.Action(this, items);
    }


    public void draw(GraphicsContext gc)  {

        gc.drawImage(cur_picture, getX() - 43, getY() - 46);
    }
}
