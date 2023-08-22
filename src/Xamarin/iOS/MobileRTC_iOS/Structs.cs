using ObjCRuntime;

namespace Zoomios
{
    [Native]
    public enum MobileRTCSDKError : ulong
    {
        Success = 0,
        NoImpl,
        WrongUsage,
        InvalidParameter,
        ModuleLoadFailed,
        MemoryFailed,
        ServiceFailed,
        Uninitialize,
        Unauthentication,
        NoRecordingInprocess,
        TranscoderNoFound,
        VideoNotReady,
        NoPermission,
        Unknown,
        OtherSdkInstanceRunning,
        InternalError,
        NoAudiodeviceIsFound,
        NoVideoDeviceIsFound,
        TooFrequentCall,
        FailAssignUserPrivilege,
        MeetingDontSupportFeature,
        MeetingNotShareSender,
        MeetingYouHaveNoShare,
        MeetingViewtypeParameterIsWrong,
        MeetingAnnotationIsOff,
        SettingOsDontSupport,
        EmailLoginIsDisabled,
        HardwareNotMeetForVb,
        NeedUserConfirmRecordDisclaimer,
        NoShareData,
        ShareCannotSubscribeMyself,
        NotInMeeting,
        MeetingCallOutFailed,
        NotSupportMultiStreamVideoUser
    }

    [Native]
    public enum MobileRTCAuthError : ulong
    {
        Success,
        KeyOrSecretEmpty,
        KeyOrSecretWrong,
        AccountNotSupport,
        AccountNotEnableSDK,
        Unknown,
        ServiceBusy,
        None,
        OverTime,
        NetworkIssue,
        ClientIncompatible,
        TokenWrong
    }

    [Native]
    public enum MobileRTCLoginFailReason : ulong
    {
        Success,
        EmailLoginDisable,
        UserNotExist,
        WrongPassword,
        AccountLocked,
        SDKNeedUpdate,
        TooManyFailedAttempts,
        SMSCodeError,
        SMSCodeExpired,
        PhoneNumberFormatInValid,
        LoginTokenInvalid,
        UserDisagreeLoginDisclaimer,
        MFARequired,
        NeedBirthdayAsk,
        OtherIssue = 100,
        InvalidArguments,
        SDKNotAuthorized,
        InAutoLoginProcess,
        AlreayLoggedin
    }

    [Native]
    public enum MobileRTCMeetError : ulong
    {
        Success = 0,
        NetworkError = 1,
        ReconnectError = 2,
        MMRError = 3,
        PasswordError = 4,
        SessionError = 5,
        MeetingOver = 6,
        MeetingNotStart = 7,
        MeetingNotExist = 8,
        MeetingUserFull = 9,
        MeetingClientIncompatible = 10,
        NoMMR = 11,
        MeetingLocked = 12,
        MeetingRestricted = 13,
        MeetingRestrictedJBH = 14,
        CannotEmitWebRequest = 15,
        CannotStartTokenExpire = 16,
        VideoError = 17,
        AudioAutoStartError = 18,
        RegisterWebinarFull = 19,
        RegisterWebinarHostRegister = 20,
        RegisterWebinarPanelistRegister = 21,
        RegisterWebinarDeniedEmail = 22,
        RegisterWebinarEnforceLogin = 23,
        ZCCertificateChanged = 24,
        VanityNotExist = 27,
        JoinWebinarWithSameEmail = 28,
        WriteConfigFile = 50,
        RemovedByHost = 61,
        HostDisallowOutsideUserJoin = 62,
        InvalidArguments = WriteConfigFile + 100,
        InvalidUserType,
        InAnotherMeeting,
        TooFrequenceCall,
        WrongUsage,
        Failed,
        VBBase = 200,
        VBSetError = VBBase,
        VBMaximumNum,
        VBSaveImage,
        VBRemoveNone,
        VBNoSupport,
        VBGreenScreenNoSupport,
        AppPrivilegeTokenError = 500,
        Unknown
    }

    [Native]
    public enum MobileRTCMeetingState : ulong
    {
        Idle,
        Connecting,
        WaitingForHost,
        InMeeting,
        Disconnecting,
        Reconnecting,
        Failed,
        Ended,
        Unknow,
        Locked,
        Unlocked,
        InWaitingRoom,
        WebinarPromote,
        WebinarDePromote,
        JoinBO,
        LeaveBO
    }

    [Native]
    public enum MobileRTCUserType : ulong
    {
        Facebook = 0,
        GoogleOAuth = 2,
        APIUser = 99,
        ZoomUser = 100,
        SSOUser = 101,
        Unknown = 102
    }

    [Native]
    public enum LeaveMeetingCmd : ulong
    {
        Leave,
        End
    }

    [Native]
    public enum JBHCmd : ulong
    {
        Show,
        Hide
    }

    [Native]
    public enum DialOutStatus : ulong
    {
        Unknown = 0,
        Calling,
        Ringing,
        Accepted,
        Busy,
        NotAvailable,
        UserHangUp,
        OtherFail,
        JoinSuccess,
        TimeOut,
        ZoomStartCancelCall,
        ZoomCallCanceled,
        ZoomCancelCallFail,
        NoAnswer,
        BlockNoHost,
        BlockHighRate,
        BlockTooFrequent
    }

    [Native]
    public enum H323CallOutStatus : ulong
    {
        Success = 0,
        Ring,
        Timeout,
        Busy,
        Decline,
        Failed
    }

    [Native]
    public enum MobileRTCH323ParingStatus : ulong
    {
        Success = 0,
        MeetingNotExisted,
        PermissionDenied,
        ParingcodeNotExisted,
        Error
    }

    [Native]
    public enum MobileRTCComponentType : ulong
    {
        Def = 0,
        Chat,
        Ft,
        Audio,
        Video,
        As
    }

    [Native]
    public enum MobileRTCVideoQuality : long
    {
        Unknown = 0,
        Bad = 1,
        Normal = 2,
        Good = 3
    }

    [Native]
    public enum MobileRTCNetworkQuality : long
    {
        Unknown = -1,
        VeryBad = 0,
        Bad = 1,
        NotGood = 2,
        Normal = 3,
        Good = 4,
        Excellent = 5
    }

    [Native]
    public enum MobileRTCAudioError : ulong
    {
        Success = 0,
        AudioPermissionDenied = 1,
        AudioNotConnected = 2,
        CannotUnmuteMyAudio = 3,
        Failed = 4
    }

    [Native]
    public enum MobileRTC_AudioStatus : ulong
    {
        None = 0,
        Audio_Muted = 1,
        Audio_UnMuted = 2,
        Audio_Muted_ByHost = 3,
        Audio_UnMuted_ByHost = 4,
        Audio_MutedAll_ByHost = 5,
        Audio_UnMutedAll_ByHost = 6
    }

    [Native]
    public enum MobileRTC_VideoStatus : ulong
    {
        On = 0,
        Off = 1,
        Muted_ByHost = 2
    }

    [Native]
    public enum MobileRTCCameraError : ulong
    {
        Success = 0,
        CameraPermissionDenied = 1,
        VideoNotSending = 2
    }

    [Native]
    public enum MobileRTCLiveStreamStatus : ulong
    {
        Successed = 0,
        FailedOrEnded = 1,
        Timeout = 2
    }

    [Native]
    public enum MobileRTCClaimHostError : ulong
    {
        Successed = 0,
        HostKeyError = 1,
        NetWorkError = 2
    }

    [Native]
    public enum MobileRTCSendChatError : ulong
    {
        Successed = 0,
        Failed = 1,
        PermissionDenied = 2
    }

    [Native]
    public enum MobileRTCAnnotationError : ulong
    {
        Successed = 0,
        Failed = 1,
        PermissionDenied = 2
    }

    [Native]
    public enum MobileRTCCMRError : ulong
    {
        Successed = 0,
        Failed = 1,
        StorageFull = 2
    }

    [Native]
    public enum MobileRTCJoinMeetingInfo : ulong
    {
        NeedName = 0,
        NeedPassword = 1,
        WrongPassword = 2,
        NeedNameAndPwd = 3
    }

    [Native]
    public enum MobileRTCMicrophoneError : ulong
    {
        MicMuted = 0,
        FeedbackDetected = 1,
        MicUnavailable = 2
    }

    [Native]
    public enum MobileRTCMeetingEndReason : ulong
    {
        SelfLeave = 0,
        RemovedByHost = 1,
        EndByHost = 2,
        JBHTimeout = 3,
        FreeMeetingTimeout = 4,
        NoAteendee = 5,
        HostEndForAnotherMeeting = 6,
        ConnectBroken = 7,
        Unknown
    }

    [Native]
    public enum MobileRTCRemoteControlError : ulong
    {
        Successed = 0,
        Stop = 1,
        Failed = 2,
        PermissionDenied = 3
    }

    [Native]
    public enum MobileRTCAudioOutput : ulong
    {
        Unknown = 0,
        Receiver = 1,
        Speaker = 2,
        Headphones = 3,
        Bluetooth = 4
    }

    [Native]
    public enum MobileRTCChatAllowAttendeeChat : ulong
    {
        None = 1,
        All = 2,
        Panelist = 3
    }

    [Native]
    public enum MobileRTCWebinarPromoteorDepromoteError : ulong
    {
        Success = 0,
        Webinar_Panelist_Capacity_Exceed = 3035,
        Not_Found_Webinar_Attendee = 3029
    }

    [Native]
    public enum MobileRTCMeetingItemAudioType : ulong
    {
        Unknown = 0,
        TelephoneOnly = 1,
        VoipOnly = 2,
        TelephoneAndVoip = 3,
        MobileRTCMeetingItemAudioType_3rdPartyAudio = 4
    }

    [Native]
    public enum MobileRTCMeetingItemRecordType : ulong
    {
        AutoRecordDisabled = 0,
        LocalRecord = 1,
        CloudRecord = 2,
        Unknown = 3
    }

    [Native]
    public enum MobileRTCMeetingChatPriviledgeType : ulong
    {
        Unknown = 0,
        Everyone_Publicly_And_Privately,
        Host_Only,
        No_One,
        Everyone_Publicly
    }

    [Native]
    public enum MobileRTCPanelistChatPrivilegeType : ulong
    {
        Invalid = 0,
        Panelist = 1,
        All = 2
    }

    [Native]
    public enum MobileRTCChatMessageType : ulong
    {
        None = 0,
        All,
        All_Panelist,
        Individual_Panelist,
        Individual,
        WaitingRoomUsers
    }

    [Native]
    public enum MobileRTCChatMessageDeleteType : ulong
    {
        None = 0,
        Self,
        Host,
        Dlp
    }

    [Native]
    public enum MobileRTCVideoType : ulong
    {
        VideoData = 1,
        ShareData
    }

    [Native]
    public enum MobileRTCVideoResolution : ulong
    {
        MobileRTCVideoResolution_90 = 0,
        MobileRTCVideoResolution_180,
        MobileRTCVideoResolution_360,
        MobileRTCVideoResolution_720
    }

    [Native]
    public enum MobileRTCVideoRawDataFormat : ulong
    {
        MobileRTCVideoRawDataFormatI420 = 1
    }

    [Native]
    public enum MobileRTCFrameDataFormat : ulong
    {
        MobileRTCFrameDataFormat_I420 = 1,
        Limit
    }

    [Native]
    public enum MobileRTCVideoRawDataRotation : long
    {
        None = 1,
        MobileRTCVideoRawDataRotation90,
        MobileRTCVideoRawDataRotation180,
        MobileRTCVideoRawDataRotation270
    }

    [Native]
    public enum MobileRTCRawDataError : ulong
    {
        Success = 0,
        Uninitialized,
        Malloc_Failed,
        Wrongusage,
        Invalid_Param,
        Not_In_Meeting,
        No_License,
        Unknow,
        Video_Module_Not_Ready,
        Video_Module_Error,
        Video_device_error,
        No_Video_Data,
        Share_Module_Not_Ready,
        Share_Module_Error,
        No_Share_Data,
        Share_Cannot_Subscribe_Myself,
        Audio_Module_Not_Ready,
        Audio_Module_Error,
        No_Audio_Data,
        Send_Too_Frequently,
        Can_Not_Change_Virtual_Device,
        Not_Join_Audio
    }

    [Native]
    public enum MobileRTCRawDataMemoryMode : ulong
    {
        Stack = 0,
        Heap
    }

    [Native]
    public enum MobileRTC_ZoomLocale : ulong
    {
        Default = 0,
        Cn
    }

    [Native]
    public enum MobileRTCSMSVerifyResult : ulong
    {
        Succ = 0,
        RealNameAuthErrorIdentifyCode,
        RealNameAuthIdentifyCodeExpired,
        RealNameAuthBypassVerify,
        RealNameAuthUnknownError
    }

    [Native]
    public enum MobileRTCSMSRetrieveResult : ulong
    {
        Succ = 0,
        SendSMSFailed,
        RequestFailed,
        InvalidPhoneNum,
        PhoneNumAlreadyBound,
        PhoneNumSendTooFrequent,
        BypassVerify
    }

    [Native]
    public enum MobileRTCMinimizeMeetingState : ulong
    {
        ShowMinimizeMeeting = 0,
        BackFullScreenMeeting
    }

    [Native]
    public enum FreeMeetingNeedUpgradeType : ulong
    {
        None = 0,
        ByAdmin,
        ByGifturl
    }

    [Native]
    public enum MobileRTCBOStatus : ulong
    {
        Invalid = 0,
        Edit = 1,
        Started,
        Stopping,
        Ended
    }

    [Native]
    public enum MobileRTCBOHelpReply : ulong
    {
        Idle = 0,
        Busy,
        Ignore,
        alreadyInBO
    }

    [Native]
    public enum MobileRTCBOControllerError : ulong
    {
        NullPointer = 0,
        WrongCurrentStatus,
        TokenNotReady,
        NoPrivilege,
        BoListIsUploading,
        UploadFail,
        NoOneHasBeenAssigned,
        Unknown = 100
    }

    [Native]
    public enum MobileRTCBOPreAssignBODataStatus : ulong
    {
        None = 0,
        Downloading,
        Download_Ok,
        Download_Fail
    }

    [Native]
    public enum MobileRTCDirectShareStatus : ulong
    {
        Unknown = 0,
        Connecting,
        In_Direct_Share_Mode,
        Ended,
        Need_MeetingID_Or_PairingCode,
        NetWork_Error,
        Other_Error,
        WrongMeetingID_Or_SharingKey,
        Need_Input_New_ParingCode,
        DirectShare_Prepared
    }

    [Native]
    public enum MobileRTCEmojiReactionType : ulong
    {
        Unknown = 0,
        Clap,
        Thumbsup,
        Heart,
        Joy,
        Openmouth,
        Tada
    }

    [Native]
    public enum MobileRTCEmojiFeedbackType : ulong
    {
        None,
        Yes,
        No,
        SpeedUp,
        SlowDown,
        Away
    }

    [Native]
    public enum MobileRTCEmojiReactionSkinTone : ulong
    {
        Unknown = 0,
        Default,
        Light,
        MediumLight,
        Medium,
        MediumDark,
        Dark
    }

    [Native]
    public enum MobileRTCMeetingType : ulong
    {
        None,
        Normal,
        BreakoutRoom,
        Webinar
    }

    [Native]
    public enum MobileRTCUserRole : ulong
    {
        None,
        Host,
        CoHost,
        Attendee,
        Panelist,
        BreakoutRoom_Moderator
    }

    [Native]
    public enum MobileRTCRecordingStatus : ulong
    {
        Start,
        Stop,
        Pause,
        Connecting,
        DiskFull
    }

    [Native]
    public enum MobileRTCSharingStatus : ulong
    {
        Self_Send_Begin,
        Self_Send_End,
        Other_Share_Begin,
        Other_Share_End,
        View_Other_Sharing,
        Pause,
        Resume,
        OtherPureAudioShareStart,
        OtherPureAudioShareStop
    }

    [Native]
    public enum MobileRTCShareSettingType : ulong
    {
        None,
        LockShare,
        HostGrab,
        AnyoneGrab,
        MultiShare
    }

    [Native]
    public enum MobileRTCVBType : long
    {
        None,
        Blur,
        Item
    }

    [Native]
    public enum MobileRTCSubscribeFailReason : long
    {
        None = 0,
        ViewOnly,
        NotInMeeting,
        NotSupport1080P,
        HasSubscribe720P,
        HasSubscribeExceededLimit
    }

    [Native]
    public enum MobileRTCANNError : ulong
    {
        Success = 0,
        NotInMeeting = 1,
        NotCustomUI = 2,
        FeatureNotSupport = 3
    }

    [Native]
    public enum MobileRTCLiveTranscriptionStatus : ulong
    {
        Unknown = 0,
        Stop = 1,
        Start = 2,
        Connecting = 3,
        UserSub = 4
    }

    [Native]
    public enum MobileRTCLiveTranscriptionOperationType : ulong
    {
        None = 0,
        Add = 1,
        Update = 2,
        Delete = 3,
        Complete = 4,
        NotSupported = 5
    }

    [Native]
    public enum MobileRTCSignInterpretationStatus : long
    {
        Initial,
        Started,
        Stopped
    }

    [Native]
    public enum MobileRTCNotificationServiceStatus : long
    {
        None = 0,
        Starting,
        Started,
        StartFailed,
        Closed
    }

    [Native]
    public enum MobileRTCInMeetingSupportAudioType : long
    {
        None = 0,
        Voip = 1,
        Telephone = 1L << 1
    }

    [Native]
    public enum MobileRTCAttendeeViewMode : long
    {
        None,
        FollowHost,
        Speaker,
        Gallery,
        Sharing_Standard,
        Sharing_SidebysideSpeaker,
        Sharing_SidebysideGallery
    }

    [Native]
    public enum MobileRTCLocalRecordingRequestPrivilegeStatus : ulong
    {
        None,
        AllowRequest,
        AutoGrant,
        AutoDeny
    }

    [Native]
    public enum MobileRTCReminderType : ulong
    {
        Login,
        StartOrJoinMeeting,
        RecordReminder,
        RecordDisclaimer,
        LiveStreamDisclaimer,
        ArchiveDisclaimer,
        WebinarAsPanelistJoin,
        TermsOfService,
        SmartSummaryDisclaimer
    }

    [Native]
    public enum MobileRTCInviteMeetingStatus : long
    {
        Accepted,
        Declined,
        Canceled,
        Timeout
    }

    [Native]
    public enum MobileRTCPresenceStatus : long
    {
        None,
        Available,
        UnAvailable,
        InMeeting,
        Busy,
        DoNotDisturb,
        Away,
        PhoneCall,
        Presenting,
        Calendar,
        OutOfOffice
    }

    [Native]
    public enum MobileRTCAutoFramingMode : long
    {
        None,
        CenterCoordinates,
        FaceRecognition
    }

    [Native]
    public enum MobileRTCFaceRecognitionFailStrategy : long
    {
        None,
        Remain,
        UsingCenterCoordinates,
        UsingOriginalVideo
    }

    [Native]
    public enum MobileRTCAudioChannel : long
    {
        Mono,
        Stereo
    }

    [Native]
    public enum MobileRTCBOUserStatus : ulong
    {
        Unassigned = 1,
        NotJoin = 2,
        InBO = 3
    }

    [Native]
    public enum MobileRTCBOStopCountDown : ulong
    {
        Not_CountDown = 0,
        Seconds_10,
        Seconds_15,
        Seconds_30,
        Seconds_60,
        Seconds_120
    }

    [Native]
    public enum MobileRTCAudioType : ulong
    {
        VoIP = 0,
        Telephony,
        None
    }

    [Native]
    public enum MobileRTCFeedbackType : ulong
    {
        None = 0,
        Hand,
        Yes,
        No,
        Fast,
        Slow,
        Good,
        Bad,
        Clap,
        Coffee,
        Clock,
        Emoji
    }

    public enum MobileRTCDeviceType : uint
    {
        H323 = 1,
        Sip,
        Both
    }

    public enum MobileRTCDeviceEncryptType : uint
    {
        None = 0,
        Encrypt,
        Auto
    }

    public enum MobileRTCChatGroup : uint
    {
        All = 0,
        Panelists = 1,
        WaitingRoomUsers = 2
    }

    public enum MobileRTCVideoAspect : uint
    {
        Original = 0,
        Full_Filled = 1,
        LetterBox = 2,
        PanAndScan = 3
    }

    [Native]
    public enum MobileRTCAnnoTool : ulong
    {
        None = 0,
        Pen,
        HighLighter,
        AutoLine,
        AutoRectangle,
        AutoEllipse,
        AutoArrow,
        AutoArrow2,
        AutoRectangleFill,
        AutoEllipseFill,
        SpotLight,
        Arrow,
        Eraser,
        Picker,
        AutoRectangleSemiFill,
        AutoEllipseSemiFill,
        AutoDoubleArrow,
        AutoDiamond,
        AutoStampArrow,
        AutoStampCheck,
        AutoStampX,
        AutoStampStar,
        AutoStampHeart,
        AutoStampQm
    }

    [Native]
    public enum MobileRTCAnnoClearType : ulong
    {
        All = 0,
        My,
        Others
    }

    public enum MobileRTCRemoteControlInputType : uint
    {
        Del,
        Return
    }

    [Native]
    public enum MobileRTCWaitingRoomLayoutType : ulong
    {
        Default = 0,
        Logo,
        Video
    }

    [Native]
    public enum MobileRTCCustomWaitingRoomDataStatus : ulong
    {
        Init,
        Downloading,
        Download_OK,
        Download_Fail
    }
}
