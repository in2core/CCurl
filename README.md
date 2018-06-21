# CCurl

A Swift wrapper around [libcurl][1] that works with Linux.
Because `curl_easy_setopt` is a variadic function and so is not imported by Swift,
additional wrapper functions are provided to get around the problem, such as:

* `curl_easy_setopt_string`
* `curl_easy_setopt_bool`

## Dependencies

For Linux you need:

`sudo apt-get install libcurl4-openssl-dev`

## Usage

This component is set up to be used with the [Swift Package Manager][2].

Add this line to your `dependencies` section:

```swift
.package(url: "https://github.com/in2core/CCurl.git", .branch("master"))
```

## Example Application

In a new directory, create `Package.swift`:

```swift
// swift-tools-version:4.0

import PackageDescription

let package = Package(
    name: "CCurlTest",
    products: [
        .executable(name: "CCurlTest", targets: ["CCurlTest"])
    ],
    dependencies: [
        .package(url: "https://github.com/in2core/CCurl.git", .branch("master"))
    ],
    targets: [
        .target(name: "CCurlTest", dependencies: ["CCurl"], path: ".")
    ]
)
```

Now create `main.swift`:

```swift
import CCurl

let handle = curl_easy_init()

curl_easy_setopt_string(handle, CURLOPT_URL, "http://www.example.com")
curl_easy_setopt_bool(handle, CURLOPT_VERBOSE, true)

let ret = curl_easy_perform(handle)
if let error = curl_easy_strerror(ret) {
    print("error = \(error)")
}
print("ret = \(ret)")
```

Build the app: `swift build`

Run the app: `.build/debug/CCurlTest`

[1]: http://curl.haxx.se/libcurl/
[2]: https://swift.org/package-manager/
