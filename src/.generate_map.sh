#!/bin/bash

# 테스트 파일이 저장될 디렉토리 생성
mkdir -p test_maps

# 정상적인 맵 파일 생성
cat <<EOL > test_maps/valid_map.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N001
100001
111111
EOL

# 잘못된 키를 포함한 맵 (오류 발생)
cat <<EOL > test_maps/invalid_key.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
XX ./textures/wrong_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N001
100001
111111
EOL

# 중복 키 오류 발생
cat <<EOL > test_maps/duplicate_keys.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220
NO ./textures/another_north_texture.xpm

111111
100001
10N001
100001
111111
EOL

# 잘못된 색상 코드 (범위를 벗어난 값)
cat <<EOL > test_maps/invalid_color.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 300,100,0
C 225,30,220

111111
100001
10N001
100001
111111
EOL

# 잘못된 맵 형식 (닫히지 않은 맵)
cat <<EOL > test_maps/unclosed_map.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N001
100001
11011
EOL

# 누락된 키 설정 맵
cat <<EOL > test_maps/missing_keys.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N001
100001
111111
EOL

# 여러 플레이어 위치 맵
cat <<EOL > test_maps/multiple_players.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
1N0001
10S001
1E0001
111111
EOL

# 빈 맵 파일
cat <<EOL > test_maps/empty_map.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220
EOL

# 공백이 포함된 맵 파일
cat <<EOL > test_maps/map_with_spaces.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220


111111

100001
10N001

100001
111111
EOL

# 잘못된 파일 확장자 맵
cat <<EOL > test_maps/wrong_extension.txt
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N001
100001
111111
EOL

# 유효하지 않은 문자가 포함된 맵 파일
cat <<EOL > test_maps/invalid_characters.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
1000X1
10N001
100001
111111
EOL

# 맵 경계가 열린 맵
cat <<EOL > test_maps/open_boundary_map.cub
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,220

111111
100001
10N00
100001
111111
EOL

# 실행 완료 메시지
echo "테스트용 .cub 파일들이 'test_maps' 디렉토리에 생성되었습니다."
