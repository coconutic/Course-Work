package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/21/16.
 */
public class VacumCleaner extends DrawItems implements Serializable{

    private static Image image_of_vacumcleaner;

    private boolean IsTurnOn;


    public  void setIsTurnOn(boolean value) { IsTurnOn = value;}
    public boolean getIsTurnOn() { return IsTurnOn;}

    public VacumCleaner(int x,int  y)
    {
        setX(x);
        setY(y);
        image_of_vacumcleaner= new Image("images/vacumcleaner.png");
        IsTurnOn = false;
    }

    public void draw(GraphicsContext gc)
    {
        gc.drawImage(image_of_vacumcleaner, getX() - 16, getY() - 16);
    }
}
