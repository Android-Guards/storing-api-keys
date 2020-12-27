package com.example.nativeapikeys

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.nativeapikeys.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.firstApikey.text = "API key #1: ${firstApiKey()}"
        binding.secondApikey.text = "API key #2: ${secondApiKey()}"
        binding.thirdApikey.text = "API key #3: ${thirdApiKey()}"
    }

    external fun firstApiKey(): String
    external fun secondApiKey(): String
    external fun thirdApiKey(): String

    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }
}
