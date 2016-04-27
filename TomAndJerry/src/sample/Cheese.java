package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/5/16.
 */
public class Cheese extends DrawItems implements Serializable, IEatable{

    public static final int changeSpeed = -1;

    public int score;
    public boolean IsEaten;

    public void draw(GraphicsContext gc)
    {
    }

    @Override
    public boolean isEaten() {

        return IsEaten;
    }

    @Override
    public  int getScore() {
        return score;
    }

    @Override
    public int getSpeed() {
        return changeSpeed;
    }

    @Override
    public void eat() {
        IsEaten = true;
    }
}
