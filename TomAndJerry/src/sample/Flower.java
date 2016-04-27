package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/21/16.
 */
public class Flower extends DrawItems implements Serializable{
    private static Image picture_of_flower;

    public void setPicture_of_flower(int index){
        if (index == 1)
        {
            picture_of_flower = new Image("/images/flower.png");
        } else
        {
            picture_of_flower = new Image("/images/flowerWithE.png");
        }
    }

    public static Image getPicture_of_flower() {
        return picture_of_flower;
    }

    public Flower(int x, int y){
        setX(x);
        setY(y);
        picture_of_flower = new Image("/images/flower.png");
    }

    public void draw(GraphicsContext gc)
    {
        gc.drawImage(picture_of_flower, getX() - 32, getY() - 32);
    }
}
