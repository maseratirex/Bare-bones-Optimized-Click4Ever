#include <Carbon/Carbon.h>

CGEventRef keyCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    CGKeyCode keycode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    if (keycode == kVK_ANSI_L)
    {
        if (type == kCGEventKeyDown)
        {
            printf("The 'l' key was pressed.\n");
        }
        else
        {
            printf("The 'l' key was released.\n");
        }
    }

    return NULL;
}

int main() {
    CGEventMask keyMask = CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventKeyUp);
    CFMachPortRef keyEventTap = CGEventTapCreate(kCGSessionEventTap,
                                   kCGHeadInsertEventTap,
                                   kCGEventTapOptionListenOnly,
                                   keyMask,
                                   keyCallback,
                                   NULL);

    if (!keyEventTap) {
        fprintf(stderr, "Failed to create event tap.\n");
        exit(1);
    }

    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, keyEventTap, 0);

    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

    CGEventTapEnable(keyEventTap, true);

    CFRunLoopRun();

    CFRelease(runLoopSource);
    CFRelease(keyEventTap);
    return 0;
}
