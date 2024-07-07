#include <Carbon/Carbon.h>

void leftMouseReleaseAtPoint(CGPoint point) {
    CGEventRef clickEvent = CGEventCreateMouseEvent(
        NULL,
        kCGEventLeftMouseUp,
        point,
        kCGMouseButtonLeft
    );

    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);
}

void leftMousePressAtPoint(CGPoint point) {
    CGEventRef clickEvent = CGEventCreateMouseEvent(
        NULL,
        kCGEventLeftMouseDown,
        point,
        kCGMouseButtonLeft
    );

    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);
}

void rightMouseReleaseAtPoint(CGPoint point) {
    CGEventRef clickEvent = CGEventCreateMouseEvent(
        NULL,
        kCGEventRightMouseUp,
        point,
        kCGMouseButtonRight
    );

    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);
}

void rightMousePressAtPoint(CGPoint point) {
    CGEventRef clickEvent = CGEventCreateMouseEvent(
        NULL,
        kCGEventRightMouseDown,
        point,
        kCGMouseButtonRight
    );

    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);
}

CGPoint getMouseCursorLocation() {
    CGEventRef dummyEvent = CGEventCreate(NULL);
    CGPoint mousePoint = CGEventGetLocation(dummyEvent);
    CFRelease(dummyEvent);
    return mousePoint;
}

int main() {
    // Simulate a left click at (100, 100)
    // CGPoint point = { 100, 100 };
    // leftMousePressAtPoint(point);
    // leftMouseReleaseAtPoint(point);
    
    // Simulate a right click at the current mouse point
    rightMousePressAtPoint(getMouseCursorLocation());
    rightMouseReleaseAtPoint(getMouseCursorLocation());

    return 0;
}
