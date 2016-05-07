package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;
import java.util.ArrayList;

/**
 * Created by katrin on 3/3/16.
 */
public class CatTom extends DrawItems implements IMoveble, Serializable, IEnemy{

    private static Image cat;
    private static CatStrategies.Strategy strategy;

    private transient static int[] dx = {4, 4};
    private transient static int[] dy = { -4, 0};

    private transient static int x_vc = 270;
    private transient static int y_vc = 600;

    private int lastpos;

    public ArrayList<Position> pos;
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
        cat = new Image("/images/cat/cat_left.png");
        lastpos = 0;

        setX(x);
        setY(y);
        setCalmStrategy();
        System.out.println("Tom is ready to run for a mouse");
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
        gc.drawImage(cat, getX() - 43, getY() - 46);
    }
}
