package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/5/16.
 */
public class Cheese extends DrawItems implements Serializable, IEatable{

    public static final int changeSpeed = -1;
    private static Image image_of_cheese;
    public static int score = 50;

    private boolean IsEaten;

    public Cheese(int x,int  y)
    {
        setX(x);
        setY(y);

        image_of_cheese = new Image("images/cheese.png");
        IsEaten = false;
    }

    public void draw(GraphicsContext gc)
    {
        if(IsEaten == false)
        {
            gc.drawImage(image_of_cheese, getX() - 16, getY() - 16);
        }
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
