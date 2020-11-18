package com.numbers.osweek14;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ListView list_view;
    private ArrayAdapter<String> adapter;
    private ArrayList<String> tasks = new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        list_view = findViewById(R.id.list_todo);
        adapter = new ArrayAdapter<String>(this, R.layout.todo_item, R.id.task_title, tasks);
        list_view.setAdapter(adapter);
        list_view.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, final View view, int position, long id) {
                        TextView removable = view.findViewById(R.id.task_title);
                        String task = removable.getText().toString();
                        removeItem(task);
            }
        });
        list_view.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                System.out.println();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                System.out.println();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case R.id.add_task:
                final EditText taskEditText = new EditText(this);
                AlertDialog dialog = new AlertDialog.Builder(this)
                        .setTitle("Add new task")
                        .setMessage("What do you want to do next?")
                        .setView(taskEditText)
                        .setPositiveButton("Add", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                String task = String.valueOf(taskEditText.getText());
                                tasks.add(task);
                                adapter.notifyDataSetChanged();
                            }
                        }).setNegativeButton("Cancel", null)
                        .create();
                dialog.show();
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void addItem ( String itemText ){
        tasks.add( itemText );
        adapter.notifyDataSetChanged () ;
    }
    private void removeItem ( String itemText ) {
        tasks.remove ( itemText );
        adapter.notifyDataSetChanged () ;
    }
}