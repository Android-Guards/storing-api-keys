# Хранение ключей API в нативном коде

⚠️ Этот репозиторий демонстриует **плохие практики** и выполняет роль учебного материала для [этого](https://www.youtube.com/watch?v=LpOvHhpcVG4) видео 

Скрипт для перехвата ключей
```javascript
Java.perform(function () {
    console.log("\n[*] Run instrumentation\n");

    var nativeInspection = Java.use("com.example.nativeapikeys.MainActivity")

    nativeInspection.firstApiKey.overload().implementation = function () {
        console.log("[*] Calling firstApiKey()")

        var key = this.firstApiKey()
        console.log(">>> API key #1: " + key + "\n")

        return key
    }

    nativeInspection.secondApiKey.overload().implementation = function () {
        console.log("[*] Calling secondApiKey()")

        var key = this.secondApiKey()
        console.log(">>> API key #2: " + key + "\n")

        return key
    }

    nativeInspection.thirdApiKey.overload().implementation = function () {
        console.log("[*] Calling thirdApiKey()")

        var key = this.thirdApiKey()
        console.log(">>> API key #3: " + key + "\n")

        return key
    }
});
```
