/**************************************************************************/
/*  error_codes.h                                                         */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

/**
 * Error codes for better error tracking and debugging.
 * These codes complement the existing Error enum and provide
 * more granular error categorization.
 */
enum class ErrorCode {
	OK = 0,

	// File and I/O errors
	FILE_NOT_FOUND = 1,
	FILE_CANT_OPEN = 2,
	FILE_CANT_READ = 3,
	FILE_CANT_WRITE = 4,
	FILE_CORRUPT = 5,
	FILE_EOF = 6,

	// Parsing errors
	PARSE_ERROR = 10,
	INVALID_FORMAT = 11,
	INVALID_DATA = 12,

	// Resource loading errors
	RESOURCE_NOT_FOUND = 20,
	RESOURCE_LOAD_FAILED = 21,
	RESOURCE_SAVE_FAILED = 22,
	RESOURCE_TIMEOUT = 23,
	RESOURCE_BUSY = 24,

	// Memory errors
	OUT_OF_MEMORY = 30,
	MEMORY_LEAK = 31,

	// Network errors
	NETWORK_TIMEOUT = 40,
	NETWORK_CONNECTION_FAILED = 41,
	NETWORK_REQUEST_FAILED = 42,

	// Validation errors
	INVALID_PARAMETER = 50,
	OUT_OF_RANGE = 51,
	NULL_POINTER = 52,

	// System errors
	UNAVAILABLE = 60,
	UNAUTHORIZED = 61,
	PERMISSION_DENIED = 62,

	// Unknown
	UNKNOWN_ERROR = 999,
};

inline const char *error_code_to_string(ErrorCode p_code) {
	switch (p_code) {
		case ErrorCode::OK:
			return "OK";
		case ErrorCode::FILE_NOT_FOUND:
			return "FILE_NOT_FOUND";
		case ErrorCode::FILE_CANT_OPEN:
			return "FILE_CANT_OPEN";
		case ErrorCode::FILE_CANT_READ:
			return "FILE_CANT_READ";
		case ErrorCode::FILE_CANT_WRITE:
			return "FILE_CANT_WRITE";
		case ErrorCode::FILE_CORRUPT:
			return "FILE_CORRUPT";
		case ErrorCode::FILE_EOF:
			return "FILE_EOF";
		case ErrorCode::PARSE_ERROR:
			return "PARSE_ERROR";
		case ErrorCode::INVALID_FORMAT:
			return "INVALID_FORMAT";
		case ErrorCode::INVALID_DATA:
			return "INVALID_DATA";
		case ErrorCode::RESOURCE_NOT_FOUND:
			return "RESOURCE_NOT_FOUND";
		case ErrorCode::RESOURCE_LOAD_FAILED:
			return "RESOURCE_LOAD_FAILED";
		case ErrorCode::RESOURCE_SAVE_FAILED:
			return "RESOURCE_SAVE_FAILED";
		case ErrorCode::RESOURCE_TIMEOUT:
			return "RESOURCE_TIMEOUT";
		case ErrorCode::RESOURCE_BUSY:
			return "RESOURCE_BUSY";
		case ErrorCode::OUT_OF_MEMORY:
			return "OUT_OF_MEMORY";
		case ErrorCode::MEMORY_LEAK:
			return "MEMORY_LEAK";
		case ErrorCode::NETWORK_TIMEOUT:
			return "NETWORK_TIMEOUT";
		case ErrorCode::NETWORK_CONNECTION_FAILED:
			return "NETWORK_CONNECTION_FAILED";
		case ErrorCode::NETWORK_REQUEST_FAILED:
			return "NETWORK_REQUEST_FAILED";
		case ErrorCode::INVALID_PARAMETER:
			return "INVALID_PARAMETER";
		case ErrorCode::OUT_OF_RANGE:
			return "OUT_OF_RANGE";
		case ErrorCode::NULL_POINTER:
			return "NULL_POINTER";
		case ErrorCode::UNAVAILABLE:
			return "UNAVAILABLE";
		case ErrorCode::UNAUTHORIZED:
			return "UNAUTHORIZED";
		case ErrorCode::PERMISSION_DENIED:
			return "PERMISSION_DENIED";
		case ErrorCode::UNKNOWN_ERROR:
			return "UNKNOWN_ERROR";
		default:
			return "UNKNOWN";
	}
}
