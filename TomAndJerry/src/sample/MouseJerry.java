package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import java.io.Serializable;
import java.util.*;

/**
 * Created by katrin on 3/2/16.
 */
public class MouseJerry extends DrawItems implements IMoveble, Serializable, IEatable {
    private int speed;
    private int count_cheese;
    public long life_time;
    private static Image picture;

    private KeyProccessing kp;

    private boolean isEaten;
    private boolean IsVisible;
    private boolean Imove;
    private boolean end;
    public boolean isDead;
    public boolean isLife_timeChanges;

    private int cur = 0;
    private int score;

    public void setPicture(int index) {
        if (index == 1) {
            picture = new Image("/images/mouse/mouse_right.png");
        } else {
            picture = new Image("/images/mouse/mouse_(.png");
        }
    }
    public void setSpeed(int value)
    {
        speed = value;
        speed = Math.max(0, speed);
    }

    public int getSpeed() {
        return speed;
    }
    public boolean getEnd() { return  end; }
    public int getScore(){ return score; }
    public boolean isLife_timeChanges() { return isLife_timeChanges; }

    public MouseJerry(int x, int y, KeyProccessing t)
    {
        life_time = 30;
        setPicture(1);

        setX(x);
        setY(y);

        kp = t;
        speed = 2;
        count_cheese = 0;
        score = 0;

        isEaten = false;
        isLife_timeChanges = false;
        IsVisible = true;
        Imove = true;
        isDead = false;
        end = false;
    }


    protected void finalize()
    {
        System.out.println("Object mouse is deleted");
    }


    public int dist(int x1, int y1, int x2, int y2)
    {
        return (int)Math.sqrt((double)((x1 - x2) * (x1 - x2)  + (y1 - y2) * (y1 - y2)));
    }

    public void  Move(ArrayList<DrawItems> items)
    {
        Iterator<DrawItems> it = items.iterator();

        while (it.hasNext()) {

            DrawItems obj = it.next();

            if (obj instanceof CatTom) {
                float dis = dist(this.getX(), this.getY(),
                        obj.getX(), obj.getY());
                if (dis <= 16 && IsVisible) {
                    this.eat();
                    this.isDead = true;
                    this.Imove = false;
                    continue;
                } else if (dis <= 150 && IsVisible) {
                            ((CatTom) obj).setAggressiveStrategy();
                        } else if (dis > 150 && IsVisible) {
                            ((CatTom) obj).setCalmStrategy();
                        }
            }

            if (obj instanceof IEatable && this != obj) {
                if (dist(this.getX(), this.getY(),
                        obj.getX(), obj.getY()) <= 50) {
                    this.add_score(((IEatable) obj).getScore());
                    this.setSpeed(getSpeed() + ((IEatable) obj).getSpeed());
                    ((IEatable) obj).eat();
                    if (obj instanceof Big_cheese){
                        count_cheese += 1;
                    }
                    if (obj instanceof Clock)
                    {
                        life_time += 15;
                        isLife_timeChanges = true;
                    }
                    continue;
                }
            }

            if (obj instanceof Hole) {
                if (dist(this.getX(), this.getY(),
                        obj.getX(), obj.getY()) <= 10) {
                    if (this.count_cheese == 5) {
                        end = true;
                        break;
                    }
                }
            }
            if (obj instanceof BlackOil || obj instanceof Mousetrap) {
                if (dist(this.getX(), this.getY(), obj.getX(), obj.getY()) <= 30) {
                    isDead = true;
                    Imove = false;
                }
            }

            if (obj instanceof Flower) {
                if (dist(this.getX(), this.getY(),
                        obj.getX(), obj.getY()) <= 25) {
                    IsVisible = false;
                    ((Flower) obj).setPicture_of_flower(2);
                } else {
                    IsVisible = true;
                    ((Flower) obj).setPicture_of_flower(1);
                }
            }
        }

        if (Imove) {
            cur++;
            if (cur < speed) {
                return;
            }
            cur = 0;
            update(items);
        }
    }


    public void update(ArrayList<DrawItems> items) {
        int dx = 0;
        int dy = 0;
        HashSet<KeyCode> temp = kp.retHashSet();
        for (KeyCode i : temp) {
            if (i == KeyCode.UP) {
                dy -= 5;
            }
            if (i == KeyCode.DOWN) {
                dy += 5;
            }
            if (i == KeyCode.LEFT) {
                dx -= 5;
            }
            if (i == KeyCode.RIGHT) {
                dx += 5;
            }
        }

        tryStep(getX() + dx, getY(), items);
        tryStep(getX(), getY() + dy, items);
    }


    public void tryStep(int newx, int newy, ArrayList<DrawItems> items){

        boolean canMove = true;

        int dx[] = {-12, 12, -12, 12};
        int dy[] = {-12, 12, 12, -12};

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

    public void draw(GraphicsContext gc) {
        if (IsVisible) {
            gc.drawImage(picture, getX() - 18, getY() - 22);
        }
        if (isDead)
        {
            this.setPicture(2);
            gc.drawImage(picture, getX() - 18, getY() - 22);
        }
    }


    public void add_score(int ad_sc){ score += ad_sc; }


    public void set_keypr(KeyProccessing k){ kp = k;}


    public int see_cheese(MouseJerry mi){
        return count_cheese;
    }

    @Override
    public void eat() {
        isEaten = true;
    }

    @Override
    public boolean isEaten() {
        return isEaten;
    }


}

    

