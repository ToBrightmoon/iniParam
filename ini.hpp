#pragma once

#include <Windows.h>
#include <locale>
#include <codecvt>

template <class T>
T GetParam(std::string Root, std::string key, std::string ini_path);

template <>
int GetParam(std::string root, std::string key, std::string ini_path)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring w_root = converter.from_bytes(root);
    std::wstring w_key = converter.from_bytes(key);
    std::wstring w_path = converter.from_bytes(ini_path);
    return GetPrivateProfileInt(w_root.c_str(), w_key.c_str(), 10, w_path.c_str());
}

template <>
std::string GetParam(std::string root, std::string key, std::string ini_path)
{
    wchar_t buffer[1024];
    std::wstring msg;

    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    std::wstring w_root = converter.from_bytes(root);
    std::wstring w_key = converter.from_bytes(key);
    std::wstring w_path = converter.from_bytes(ini_path);

    
    GetPrivateProfileString(w_root.c_str(), w_key.c_str(), L"", buffer, sizeof(buffer) / sizeof(wchar_t), w_path.c_str());
    msg = buffer;
    return converter.to_bytes(msg);
}