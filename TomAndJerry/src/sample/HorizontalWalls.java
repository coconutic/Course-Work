package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.util.Pair;

import java.io.Serializable;

/**
 * Created by katrin on 3/29/16.
 */
public class HorizontalWalls  extends DrawItems implements Serializable, IBarrier{

    private int length;
    private int corner_x, corner_y;

    private static Image picture;

    public int getCornerX() { return corner_x; }
    public int getCornerY() { return corner_y; }


    public HorizontalWalls(int x, int y, int len){
        setX(x);
        setY(y);
        corner_x = x + 22 * len;
        corner_y = y + 22;
        length = len;
    }

    public void draw(GraphicsContext gc) {
        picture = new Image("images/wall.png");
        for (int i = 0; i < length; i++){
            gc.drawImage(picture, getX() + 22 * i, getY() );
        }
    }
}
