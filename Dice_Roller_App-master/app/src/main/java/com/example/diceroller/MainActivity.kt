package com.example.diceroller

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.border
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.diceroller.ui.theme.DiceRollerTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            Surface(
                modifier = Modifier.fillMaxSize(),
                color = MaterialTheme.colorScheme.background
            ) {
                DiceRollerTheme {
                    DiceRollerApp()
                }
            }
        }
    }
}

@Composable
fun DiceWithButtonAndImage(
    title: String,
    modifier: Modifier = Modifier
        .fillMaxSize()
) {
    var result by remember { mutableStateOf(1) }
    val imageResource = when (result) {
        1 -> R.drawable.dice_1
        2 -> R.drawable.dice_2
        3 -> R.drawable.dice_3
        4 -> R.drawable.dice_4
        5 -> R.drawable.dice_5
        else -> R.drawable.dice_6
    }
    val message = when (result) {
        1 -> "Ohh boy..Ace"
        2 -> "Double down!"
        3 -> "Triple threat!"
        4 -> "On a roll!!"
        5 -> "Epic.."
        else -> "Great!!!"
    }
    Column(
        modifier = modifier,
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Top
    )
    {
        Text(
            text = title,
            fontFamily = FontFamily.Cursive,
            fontWeight = FontWeight.ExtraBold,
            fontSize = 70.sp,
            modifier = Modifier
                .padding(bottom = 80.dp)
                .padding(top = 100.dp)
        )
        Text(
            text = "You got:$result",
            fontFamily = FontFamily.Monospace,
            fontSize = 27.sp
        )

        Spacer(modifier = Modifier.height(16.dp))

        Image(painter = painterResource(imageResource), contentDescription = result.toString())

        Spacer(modifier = Modifier.height(16.dp))

        Button(onClick = { result = (1..6).random() }) {
            Text(
                stringResource(R.string.roll),
                fontSize = 25.sp,
                fontFamily = FontFamily.SansSerif
            )
        }

        Text(
            text = message,
            fontFamily = FontFamily.Monospace,
            fontSize = 27.sp,
            modifier = Modifier.padding(top = 40.dp)
        )
    }
}

@Composable
fun CopyRight(modifier: Modifier = Modifier) {
    Column(
        modifier
            .fillMaxSize()
            .padding(12.dp),
        verticalArrangement = Arrangement.Bottom,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "Ⓒ k102d",
            textAlign = TextAlign.Center,
            fontFamily = FontFamily.SansSerif,
            fontSize = 14.sp
        )
    }
}


@Composable
fun Background(modifier: Modifier = Modifier) {
    Image(
        painter = painterResource(R.drawable.diceappbg),
        contentDescription = "bg",
        alpha = 0.25F,
        contentScale = ContentScale.Crop,
        modifier = Modifier.border(
            width = 3.dp,
            color = Color.DarkGray,
        )
    )
}

@Preview(
    showBackground = true
)
@Composable
fun DiceRollerApp() {
    DiceWithButtonAndImage(title = "Dice Roller")
    CopyRight()
    Background()

}
