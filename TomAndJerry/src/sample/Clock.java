package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/21/16.
 */
public class Clock extends DrawItems implements Serializable, IEatable{
    private static final int changeSpeed = 0;
    public static final int score = 0;
    private static Image image_of_clock;

    private boolean IsEaten;

    public Clock(int x,int  y)
    {
        setX(x);
        setY(y);
        image_of_clock = new Image("images/clock.png");
        IsEaten = false;
    }

    @Override
    public boolean isEaten() {
        return IsEaten;
    }

    @Override
    public void eat() {
        IsEaten = true;
    }

    @Override
    public int getScore() {
        return score;
    }

    @Override
    public int getSpeed() {
        return changeSpeed;
    }

    public void draw(GraphicsContext gc)
    {
        if(IsEaten == false)
        {
            gc.drawImage(image_of_clock, getX() - 16, getY() - 16);
        }
    }


}
