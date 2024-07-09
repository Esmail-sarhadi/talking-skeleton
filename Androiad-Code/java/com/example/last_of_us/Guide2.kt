package com.example.last_of_us

import android.annotation.SuppressLint
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import androidx.appcompat.app.AppCompatDelegate
import androidx.core.content.res.ResourcesCompat
import www.sanju.motiontoast.MotionToast

class Guide2 : drawer() {
    @SuppressLint("MissingInflatedId")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        val inflater = LayoutInflater.from(this)
        val view7 = inflater.inflate(R.layout.activity_guide2,null,false)
        drawerLayout.addView(view7,0)
        val buttonClick = findViewById<Button>(R.id.okbtn2)
        buttonClick.setOnClickListener {
            val intent = Intent(this, Partitioning::class.java)
            startActivity(intent)
            finish()
        }
    }
    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        menuInflater.inflate(R.menu.main, menu)
        return true
    }
    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        val id = item.itemId
        if (id==R.id.action_settings){
            val intent = Intent(this, Partitioning::class.java)
            startActivity(intent)
            finish()
        }
        return super.onOptionsItemSelected(item)
    }
    override fun onBackPressed() {
        val intent = Intent(this, Partitioning::class.java)
        startActivity(intent)
        finish()
    }
}