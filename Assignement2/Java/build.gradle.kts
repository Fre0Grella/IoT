plugins {
    // Apply the java plugin to add support for Java
    java
 
    // Apply the application plugin to add support for building a CLI application
    // You can run your app via task "run": ./gradlew run
    application
}
 
repositories {
    mavenCentral()
}
 
val javaFXModules = listOf(
    "base",
    "controls",
    "fxml",
    "swing",
    "graphics"
)
 
val supportedPlatforms = listOf("linux", "mac", "win") // All required for OOP
 
dependencies {
    // JavaFX: comment out if you do not need them
    val javaFxVersion = 15
    for (platform in supportedPlatforms) {
        for (module in javaFXModules) {
            implementation("org.openjfx:javafx-$module:$javaFxVersion:$platform")
        }
    }
    implementation("io.github.java-native:jssc:2.9.5")
 
}
 
 
application {
    // Define the main class for the application
    mainClass.set("it.unibo.samplejavafx.App")
}