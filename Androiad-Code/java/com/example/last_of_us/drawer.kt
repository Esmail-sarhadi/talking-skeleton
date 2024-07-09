package com.example.last_of_us



import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Gravity
import androidx.appcompat.app.ActionBarDrawerToggle
import androidx.appcompat.app.AppCompatDelegate
import androidx.appcompat.widget.Toolbar
import androidx.core.content.res.ResourcesCompat
import androidx.drawerlayout.widget.DrawerLayout
import com.google.android.material.navigation.NavigationView
import www.sanju.motiontoast.MotionToast

open class drawer : AppCompatActivity() {

    lateinit var drawerLayout: DrawerLayout
    lateinit var actionBarToggle: ActionBarDrawerToggle
    lateinit var navView: NavigationView
    lateinit var toolbar: Toolbar
    var backPressedTime: Long = 0




    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);

        setContentView(R.layout.activity_drawer)
        toolbar = findViewById(R.id.toolbarr);
        toolbar.setTitle("")
        setSupportActionBar(toolbar);
        drawerLayout = findViewById(R.id.drawer_layout)
        actionBarToggle = ActionBarDrawerToggle(this, drawerLayout,0, 0)
        drawerLayout.addDrawerListener(actionBarToggle)
        supportActionBar?.setDisplayHomeAsUpEnabled(true)
        actionBarToggle.syncState()
        navView = findViewById(R.id.nav_view)
        navView.setNavigationItemSelectedListener { menuItem ->
            when (menuItem.itemId) {
                R.id.help -> {
                    val intent = Intent(this, Guide2::class.java)
                    startActivity(intent)
                    finish()
                    true
                }
                R.id.about_uss -> {
                    val intent = Intent(this, AboutUs::class.java)
                    startActivity(intent)
                    finish()

                    true
                }
                R.id.contacts_us -> {
                    val intent = Intent(this, ContactUs::class.java)
                    startActivity(intent)
                    finish()
                    true
                }
                else -> {
                    false
                }
            }
        }



    }

    override fun onSupportNavigateUp(): Boolean {
        drawerLayout.openDrawer(navView)
        return true
    }



}