
package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

import java.io.Serializable;
import java.util.HashSet;

/**
 * Created by katrin on 3/23/16.
 */
public class KeyProccessing implements Serializable{
    private HashSet<KeyCode> keyPressed;

    public KeyProccessing(Canvas cn) {
        keyPressed = new HashSet<KeyCode>();

        cn.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                if (event.getCode() == KeyCode.UP) {
                    keyPressed.add(KeyCode.UP);
                }
                if (event.getCode() == KeyCode.DOWN) {
                    keyPressed.add(KeyCode.DOWN);
                }
                if (event.getCode() == KeyCode.LEFT) {
                    keyPressed.add(KeyCode.LEFT);
                }
                if (event.getCode() == KeyCode.RIGHT) {
                    keyPressed.add(KeyCode.RIGHT);
                }
                if (event.getCode() == KeyCode.S) {
                    keyPressed.add(KeyCode.S);
                }
                if (event.getCode() == KeyCode.L) {
                    keyPressed.add(KeyCode.L);
                }
            }
        });

        cn.setOnKeyReleased(new EventHandler<KeyEvent>() {
        @Override
            public void handle(KeyEvent event) {
                if (event.getCode() == KeyCode.UP && keyPressed.contains(KeyCode.UP)){
                    keyPressed.remove(KeyCode.UP);
                }
                if (event.getCode() == KeyCode.DOWN && keyPressed.contains(KeyCode.DOWN)){
                    keyPressed.remove(KeyCode.DOWN);
                }
                if (event.getCode() == KeyCode.LEFT && keyPressed.contains(KeyCode.LEFT)) {
                    keyPressed.remove(KeyCode.LEFT);
                }
                if (event.getCode() == KeyCode.RIGHT && keyPressed.contains(KeyCode.RIGHT)) {
                    keyPressed.remove(KeyCode.RIGHT);
                }
                if (event.getCode() == KeyCode.S && keyPressed.contains(KeyCode.S)){
                    keyPressed.remove(KeyCode.S);
                }
                if (event.getCode() == KeyCode.L && keyPressed.contains(KeyCode.L)){
                    keyPressed.remove(KeyCode.L);
                }
            }
        });
    }

    public HashSet<KeyCode> retHashSet()
    {
        return keyPressed;
    }
}
