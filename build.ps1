$PROJECT = "\\wsl.localhost\archlinux\root\projects\c-platformer"
$RAYLIB = "C:\msys64\ucrt64"
$SRC = Get-ChildItem -Path "$PROJECT\src\*.c" | ForEach-Object { $_.FullName }

& "C:\msys64\ucrt64\bin\gcc.exe" -Wall -Wextra -g -std=c11 `
    -I"$RAYLIB\include" `
    -o "$PROJECT\main.exe" `
    $SRC `
    -lraylib -lm `
    -L"$RAYLIB\lib"

if ($LASTEXITCODE -eq 0) {
    & "$PROJECT\main.exe"
} else {
    Write-Host "Build failed" -ForegroundColor Red
}
